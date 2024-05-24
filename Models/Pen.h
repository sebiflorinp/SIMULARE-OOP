#ifndef SIMULARE_PEN_H
#define SIMULARE_PEN_H


#include <string>

class Pen {
private:
    int id;
    std::string brand;
    std::string color;
    float price;
public:
    Pen(int id, const std::string &brand, const std::string &color, float price);

    const std::string &getBrand() const;

    int getId() const;

    void setId(int id);

    void setBrand(const std::string &brand);

    const std::string &getColor() const;

    void setColor(const std::string &color);

    float getPrice() const;

    void setPrice(int price);
};



#endif //SIMULARE_PEN_H
