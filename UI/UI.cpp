#include "UI.h"
#include <QWidget>
#include <QListWidgetItem>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <sstream>

UI::UI(PenController &penController): controller(penController) {
    initUI();
    refreshList(controller.getAllPens());
}

void UI::initUI() {
    // Create the app
    auto* app = new QWidget();

    // Create the layout of the app
    auto* layout = new QGridLayout();

    // Create the buttons
    auto* sortByBrandASCButton = new QPushButton("Sort by Brand ASC");
    auto* sortByPriceDESCButton = new QPushButton("Sort by Price DESC");
    auto* unsortedButton = new QPushButton("Unsorted");

    // Create the form and its layout (form == where the details of a pen are shown)
    auto* form = new QWidget();
    auto* formLayout = new QGridLayout();

    // Create the lineEdits required for the form
    auto* brandLineEdit = new QLineEdit();
    auto* colorLineEdit = new QLineEdit();
    auto* priceLineEdit = new QLineEdit();

    // Put all elements needed for the form layout and set the layout
    formLayout->addWidget(new QLabel("Brand: "), 0, 0);
    formLayout->addWidget(brandLineEdit, 0, 1, 1, 3);

    formLayout->addWidget(new QLabel("Color: "), 1, 0);
    formLayout->addWidget(colorLineEdit, 1, 1, 1, 3);

    formLayout->addWidget(new QLabel("Price: "), 2, 0);
    formLayout->addWidget(priceLineEdit, 2, 1, 1, 3);

    form->setLayout(formLayout);

    // Add all the elements in the app layout
    layout->addWidget(list, 0,0, 2, 1);
    layout->addWidget(form, 0, 1, 1, 3);
    layout->addWidget(sortByBrandASCButton, 1, 1);
    layout->addWidget(sortByPriceDESCButton, 1, 2);
    layout->addWidget(unsortedButton, 1, 3);

    // Set the layout and display the app
    app->setLayout(layout);
    app->show();

    // Add onClick event to display in the form the details of a pen
    QObject::connect(list, &QListWidget::itemClicked, form, [=](){
        // It is assumed that only one item is clicked / selected
        // It is also assumed that the brand acts as a uid
        // Get the brand from the text
        std::string itemText = list->selectedItems()[0]->text().toStdString();

        // Get the brand from the text with stringstream
        std::stringstream stringstream(itemText);
        std::string brand;
        getline(stringstream, brand, ' ');

        // Get the details of the pen and edit the lineEdits
        Pen pen = controller.getPenByBrand(brand);
        brandLineEdit->setText(QString::fromStdString(pen.getBrand()));
        colorLineEdit->setText(QString::fromStdString(pen.getColor()));
        //priceLineEdit->setText(QString::fromStdString(); // to be solved later
    });

    // Add onClick event for the Sort by brand ASC button
    QObject::connect(sortByBrandASCButton, &QPushButton::clicked, list, [=](){
        auto sortedPens = controller.getAllPensSortedByBrandASC();
        refreshList(sortedPens);
    });

    // Add onClick event for the Sort by price DESC button
    QObject::connect(sortByPriceDESCButton, &QPushButton::clicked, list, [=](){
        auto sortedPens = controller.getAllPensSortedByPriceDESC();
        refreshList(sortedPens);
    });

    // Add onClick event for the unsorted button
    QObject::connect(unsortedButton, &QPushButton::clicked, list, [=](){
        refreshList(controller.getAllPens());
    });

}

void UI::refreshList(std::vector<Pen> pens) {
    list->clear();

    for (auto pen: pens) {
        // Use stringstream to create a formatted string because format doesn't exist in cpp 17
        std::stringstream stringstream;
        stringstream << pen.getBrand();
        stringstream << " (";
        stringstream << pen.getPrice();
        stringstream << ")";
        std::string formattedString = stringstream.str();

        list->addItem(new QListWidgetItem(QString::fromStdString(formattedString)));
    }
}
