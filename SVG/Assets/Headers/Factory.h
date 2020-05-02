#ifndef FACTORY_H
#define FACTORY_H

#include "Figure.h"

class Factory {
private:
    static std::string toLowerCase (std::string type);
public:
    static bool validNumber (std::string number);
    static Figure* getFigure (std::vector<std::string> infoStorage);
};

#endif