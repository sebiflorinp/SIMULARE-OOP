#include <QApplication>
#include <QPushButton>
#include "Repositories/PenRepository.h"
#include "Controllers/PenController.h"
#include "UI/UI.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    // Create the repository, controller and UI
    PenRepository repository = PenRepository();
    PenController controller = PenController(repository);
    UI ui = UI(controller);


    return QApplication::exec();
}
