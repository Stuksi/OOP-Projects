#ifndef FACTORY_H
#define FACTORY_H

#include "Figure.h"

/*
    Класът Factory, е помощен клас с който се индентифицират
    фигурите от какъв тип са, както има и помощни функции,
    които са за общо ползване. Всички функциите в класа са статични.
*/

class Factory {
private:
    static std::string toLowerCase (std::string type);
public:
    static bool validNumber (std::string number);
    static Figure* getFigure (std::vector<std::string> infoStorage);
};

#endif