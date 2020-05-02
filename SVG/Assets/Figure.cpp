#include "Headers\Figure.h"
#include "Headers\Factory.h"

std::istream &operator >> (std::istream &is, std::vector<Figure *>& figures) {
    // OLD METHOD
    /*
    Figure* newFigure;
    size_t size;
    std::string type;
    figures.clear();
    is >> size;
    for (size_t i = 0; i < size; i++)
    {
        is >> type;
        newFigure = Factory::getType(type);
        newFigure->read(is);
        figures.push_back(newFigure);
    }
    return is;
    */

    std::string fileTxT = "", temp;
    std::vector<std::string> values;
    size_t i = 1;

    while (is >> temp)
    {
        fileTxT += temp;
    }
    
    temp = "";

    while (fileTxT[i-1] != '<' || fileTxT[i] != 's')
    {
        if(fileTxT[i] == '\0') {
            return is;
        }
        i++;
    }
    i+=4;
    while (fileTxT[i+1] != '/' && fileTxT[i+2] != 's')
    {
        values.clear();
        temp = "";
        i++;  
        while (temp != "rect" && temp != "circle" && temp != "line")
        {
            temp += fileTxT[i];
            i++;
        } 
        values.push_back(temp);
        temp = "";
        while (fileTxT[i] != '>')
        {
            if(fileTxT[i] == '"') {
                i++;
                while (fileTxT[i] != '"')
                {
                    temp += fileTxT[i];
                    i++;
                }
                values.push_back(temp);
                temp = "";
            }
            i++;
        }
        i++;
        Figure* newFigure = Factory::getFigure(values);
        figures.push_back(newFigure);
    }
    return is;
}

std::ostream &operator << (std::ostream &os, const std::vector<Figure *>& figures) {
    // OLD
    /*
    os << figures.size() << " ";
    for (size_t i = 0; i < figures.size(); i++)
    {
        figures[i]->write(os);
    }
    return os;    
    */
    os << "<svg>\n";
    for (size_t i = 0; i < figures.size(); i++)
    {
        figures[i]->write(os);
    }
    os << "</svg>\n";
    return os;
}