#include <fstream>
#include <sstream>
#include "PenRepository.h"

void PenRepository::addPen(Pen newPen) {
    // It is assumed that the id is generated by the app (so no duplicates)
    pens.push_back(newPen);
}

Pen PenRepository::getPenById(int id) {
    // It is assumed that the pen is chosen from the UI (there is no way to ask for an id that doesn't exist)
    for (auto pen: pens) {
        if (pen.getId() == id) {
            return pen;
        }
    }
}

std::vector<Pen> PenRepository::getAllPens() {
    return pens;
}

void PenRepository::loadData() {
    // Open the file
    std::ifstream in("pens.txt");
    std::string line;
    while (getline(in, line)) {
        // Use string stream to get the values using , as a separator (better than strtok)
        std::stringstream stringstream(line);

        // The field of a pen
        int id;
        std::string brand;
        std::string color;
        float price;
        std::string field; // for ints and floats

        // Read the fields
        getline(stringstream, field, ',');
        id = stoi(field);

        getline(stringstream, brand, ',');

        getline(stringstream, color, ',');

        getline(stringstream, field, ',');
        price = stof(field);

        // Create the pen and add it in the repo
        Pen toAdd = Pen(id, brand, color, price);
        addPen(toAdd);
    }

    // Close the file
    in.close();
}

void PenRepository::saveData() {
    // Open the file
    std::ofstream out("pens.txt");

    // Save the data
    for (auto pen: pens) {
        out << pen.getId() << "," << pen.getBrand() << "," << pen.getColor() << "," << pen.getPrice() <<std::endl;
    }

    // Close the file
    out.close();
}

Pen PenRepository::getPenByBrand(std::string brand) {
    for (int i = 0; i < pens.size(); ++i) {
        if (pens[i].getBrand() == brand) {
            return pens[i];
        }
    }
}