#include "Pen.h"

Pen::Pen(int id, const std::string &brand, const std::string &color, float price) : id(id), brand(brand), color(color), price(price) {}

const std::string &Pen::getBrand() const {
    return brand;
}

void Pen::setBrand(const std::string &brand) {
    Pen::brand = brand;
}

const std::string &Pen::getColor() const {
    return color;
}

void Pen::setColor(const std::string &color) {
    Pen::color = color;
}

float Pen::getPrice() const {
    return price;
}

void Pen::setPrice(int price) {
    Pen::price = price;
}

int Pen::getId() const {
    return id;
}

void Pen::setId(int id) {
    Pen::id = id;
}
