#include "Headers\Figure.h"
#include "Headers\Factory.h"



//  Операторът е с цел за правилно прочитане на файл.
std::istream &operator >> (std::istream &is, std::vector<Figure *>& figures) {
    std::string fileTxT = "", temp;
    std::vector<std::string> values;
    size_t i = 1;

    // Първо се записва информацията от файла в низ.
    while (is >> temp)
    {
        fileTxT += temp;
    }
    
    temp = "";

    // Четем информацията от файла докато не стигнем до частта която ни интересува(фигурите).
    while (fileTxT[i-1] != '<' || fileTxT[i] != 's')
    {
        if(fileTxT[i] == '\0') {
            return is;
        }
        i++;
    }
    i+=4;
    // Четем докато не открием символът за край на частта с фигурите, като информацията записваме в масив който подаваме на класа Factory.
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

// Операторът е с цел да може да се записва информация обратно във файла, като той да има вид на svg.
std::ostream &operator << (std::ostream &os, const std::vector<Figure *>& figures) {
    os << "<svg>\n";
    for (size_t i = 0; i < figures.size(); i++)
    {
        figures[i]->write(os);
    }
    os << "</svg>\n";
    return os;
}