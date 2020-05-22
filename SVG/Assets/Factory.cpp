#include "Headers\Factory.h"
#include "Headers\Rectangle.h"
#include "Headers\Circle.h"
#include "Headers\Line.h"

/*
    Този метод е помощен с който се проверява по даден низ дали е правилно зададено число.
*/
bool Factory::validNumber (std::string number) {
    bool dot = false;
    for (size_t i = 0; i < number.length(); i++)
    {   
        if(number[i] == '.' && !dot) {
            dot = true;
            continue;
        }
        if(number[i] < '0' || number[i] > '9') {
            return false;
        }
    }
    return true;
}

/*
    Този метод е помощен с който се променя низът с типа в малки букви за по-лесно и правилно разпознаване от останалите методи.
*/
std::string Factory::toLowerCase (std::string type) {
    std::string copyOfType = type;
    for (size_t i = 0; i < type.length(); i++)
    {
        if(copyOfType[i] >= 'A' && copyOfType[i] <= 'Z') {
            copyOfType[i] += 'a' - 'A';
        }
    }
    return copyOfType;
}

/*
    "getFigure" приема масив от низове, по които разпознава типа на фигурата, както и информацията въведена след нея.
    Ако типът на фигурата или въведените параметри не са валидни се извежда съобщение в конзолата и функцията връща nullptr.
*/
Figure* Factory::getFigure (std::vector<std::string> type) {
    Figure* newFigure;
    if(toLowerCase(type[0]) == "rect" || toLowerCase(type[0]) == "rectangle" && (type.size() == 5 || type.size() == 6)  
    && validNumber(type[1]) && validNumber(type[2]) && validNumber(type[3]) && validNumber(type[4])) {
        if(type.size() == 5) {
            newFigure = new Rectangle(stod(type[1]), stod(type[2]), stod(type[3]), stod(type[4]), "Transperant");
        } else {
            newFigure = new Rectangle(stod(type[1]), stod(type[2]), stod(type[3]), stod(type[4]), type[5]);
        }
    } else if(toLowerCase(type[0]) == "circle" && (type.size() == 4 || type.size() == 5)  
    && validNumber(type[1]) && validNumber(type[2]) && validNumber(type[3])) {
        if(type.size() == 4) {
            newFigure = new Circle(stod(type[1]), stod(type[2]), stod(type[3]), "Transperant");
        } else {
            newFigure = new Circle(stod(type[1]), stod(type[2]), stod(type[3]), type[4]);
        }
    } else if(toLowerCase(type[0]) == "line" && (type.size() == 5 || type.size() == 6)  
    && validNumber(type[1]) && validNumber(type[2]) && validNumber(type[3]) && validNumber(type[4])) {
        if(type.size() == 5) {
            newFigure = new Line(stod(type[1]), stod(type[2]), stod(type[3]), stod(type[4]), "Transperant");
        } else {
            newFigure = new Line(stod(type[1]), stod(type[2]), stod(type[3]), stod(type[4]), type[5]);
        }
    } else {
        std::cout << type[0] << " is not supported or the parameters are invalid!" << std::endl;
        return nullptr;
    }
    return newFigure;
}