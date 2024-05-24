#ifndef SIMULARE_PENREPOSITORY_H
#define SIMULARE_PENREPOSITORY_H


#include <vector>
#include "../Models/Pen.h"

class PenRepository {
private:
    std::vector<Pen> pens;
public:
    /*
     * Adds a pen in the repository.
     * Preconditions: newPen: a Pen object
     * Post-conditions: -
     */
    void addPen(Pen newPen);

    /*
     * Returns the pen with the given id
     * Preconditions: id: an integer
     * Post-conditions: a Pen object
     */
    Pen getPenById(int id);

    /*
     * Returns the pen with the given brand
     * Preconditions: brand: a string
     * Post-conditions: a Pen object
     */
    Pen getPenByBrand(std::string brand);

    /*
     * Returns all the pens in the repo
     * Preconditions: -
     * Post-conditions: a vector with Pen objects
     */
    std::vector<Pen> getAllPens();

    /*
     * Loads data from the pens.txt file
     * Preconditions: -
     * Post-conditions: -
     */
    void loadData();

    /*
     * Saves the data from the repo in the pens.txt file
     * Preconditions: -
     * Post-conditions: -
     */
    void saveData();
};


#endif //SIMULARE_PENREPOSITORY_H
