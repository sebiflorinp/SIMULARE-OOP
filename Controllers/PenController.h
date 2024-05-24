#ifndef SIMULARE_PENCONTROLLER_H
#define SIMULARE_PENCONTROLLER_H


#include <string>
#include "../Repositories/PenRepository.h"

class PenController {
private:
    PenRepository& repository;
public:
    /*
     * The constructor of the PenController class.
     * Preconditions: penRepository: a reference to a PenRepository
     * Post-conditions: -
     */
    PenController(PenRepository& penRepository);

    /*
     * Adds a pen in the repository
     * Preconditions: brand: a string
     *                color: a string
     *                price: a float
     * Post-conditions: -
     */
    void addPen(std::string brand, std::string color, float price);

    /*
     * Returns the pen with the given id
     * Preconditions: id: an integer
     * Post-conditions: an instance of the Pen class
     */
    Pen getPenById(int id);

    /*
     * Returns the pen with the given brand
     * Precondition
     */
    Pen getPenByBrand(std::string brand);

    std::vector<Pen> getAllPens();

    std::vector<Pen> getAllPensSortedByBrandASC();

    std::vector<Pen> getAllPensSortedByPriceDESC();
};


#endif //SIMULARE_PENCONTROLLER_H
