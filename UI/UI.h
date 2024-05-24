#ifndef SIMULARE_UI_H
#define SIMULARE_UI_H


#include <QWidget>
#include <QListWidget>
#include "../Controllers/PenController.h"

class UI: public QWidget {
    Q_OBJECT
private:
    QListWidget* list = new QListWidget();
    PenController& controller;
public:
    UI(PenController& penController);

    void initUI();

    void refreshList(std::vector<Pen> pens);
};


#endif //SIMULARE_UI_H
