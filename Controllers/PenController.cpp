#include "PenController.h"

PenController::PenController(PenRepository &penRepository): repository(penRepository) {
    // Load data from the file
    penRepository.loadData();
}

void PenController::addPen(std::string brand, std::string color, float price) {
    // Get the id for the new pen
    int newId = 0;
    for (auto pen: repository.getAllPens()) {
        if (newId < pen.getId()) {
            newId = pen.getId();
        }
    }
    newId++;

    // Create the new pen
    Pen newPen = Pen(newId, brand, color, price);

    // Add the pen
    repository.addPen(newPen);

    // Save the data
    repository.saveData();
}

Pen PenController::getPenById(int id) {
    return repository.getPenById(id);
}

std::vector<Pen> PenController::getAllPens() {
    return repository.getAllPens();
}

Pen PenController::getPenByBrand(std::string brand) {
    return repository.getPenByBrand(brand);
}

std::vector<Pen> PenController::getAllPensSortedByBrandASC() {
    // Get a copy of the vector
    std::vector<Pen> pens = repository.getAllPens();

    // Sort the vector
    for (int i = 0; i < pens.size() - 1; ++i) {
        for (int j = i; j < pens.size(); ++j) {
            if (pens[i].getBrand() > pens[j].getBrand()) {
                Pen aux = pens[i];
                pens[i] = pens[j];
                pens[j] = aux;
            }
        }
    }

    return pens;
}

std::vector<Pen> PenController::getAllPensSortedByPriceDESC() {
    // Get a copy of the vector
    std::vector<Pen> pens = repository.getAllPens();

    // Sort the vector
    for (int i = 0; i < pens.size() - 1; ++i) {
        for (int j = i; j < pens.size(); ++j) {
            if (pens[i].getPrice() < pens[j].getPrice()) {
                Pen aux = pens[i];
                pens[i] = pens[j];
                pens[j] = aux;
            }
        }
    }

    return pens;
}
