#include "Headers\CommandHandle.h"
#include "Headers\Factory.h"

#include <fstream>

bool CommandHandle::exists(std::string fileName) {
    std::fstream file(fileName);
    return file.good();
}

bool CommandHandle::empty_File(std::string fileName) {
    std::fstream file(fileName);
    return file.peek() == std::ifstream::traits_type::eof();
}

void CommandHandle::open (std::vector<Figure *>& figures, std::vector<std::string> infoStorage, std::ifstream& r_File, std::string& fileName) {
    if(exists(infoStorage[0])) {
        fileName = infoStorage[0];
        r_File.open(fileName);
        if(!empty_File(fileName)){
            r_File >> figures;
        }
        std::cout << fileName << " opened successfully!" << std::endl;
    } else {
        std::cout << infoStorage[0] << " does not exist!" << std::endl;
    }
}

void CommandHandle::close (std::vector<Figure *>& figures, std::ifstream& r_File, std::string& fileName) {
    if(r_File.is_open()) {
        figures.clear();
        r_File.close();
        std::cout << fileName << " closed successfully!" << std::endl;
        fileName = "";
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
} 

void CommandHandle::save (std::vector<Figure *>& figures, std::ifstream& r_File, std::string& fileName) {
    if(r_File.is_open()) {
        std::ofstream w_File(fileName);
        w_File << figures;
        w_File.close();
        std::cout << "Information saved successfully to " << fileName << "!" << std::endl;
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
}

void CommandHandle::saveas (std::vector<Figure *>& figures, std::vector<std::string> infoStorage, std::ifstream& r_File) {
    if(r_File.is_open()) {
        if(!exists(infoStorage[0])){
            std::ofstream w_File(infoStorage[0]);
            w_File << figures;
            w_File.close();
            std::cout << "Information saved successfully to " << infoStorage[0] << "!" << std::endl;
        }else {
            std::cout << "The file name already exists!" << std::endl;
        }
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
}

void CommandHandle::help () {
    std::cout << "The following commands are supported:\n"
            << "Main commands: \n"
            << "   open <file>     Opens <file>\n"
            << "   close           Closes currently opened file\n"
            << "   save            Saves the currently open file\n"
            << "   saveas <file>   Saves the currently open file in <file>\n"
            << "   help            Prints this information\n"
            << "   exit            Exits the program\n"
            << "SVG commands: \n"
            << "   print                                           Prints currently entered shapes\n"
            << "   create <shapeType> <parameters>                 Creates a shape\n"
            << "   erase <n>                                       Deletes shape whit order number <n>\n"
            << "   translate <horizontal> <vertical>               Translate all the shapes\n"
            << "   translate <n> <horizontal> <vertical>           Translate shape whit order number <n>\n"
            << "   within <\"circle\"/\"rectangle\"> <parameters>      Searches for all the shapes whitin the range\n"
            << "   /parameters                                     Shows the supported parameters for every shape"
            << std::endl;
}

void CommandHandle::parameters () {
    std::cout << "The following parameters for the shapes are supported:\n"
            << "   Rectangle     \"x\", \"y\", \"width\", \"height\", \"color\"\n"
            << "   Circle        \"cx\", \"cy\", \"r\", \"color\"\n"
            << "   Line          \"x1\", \"y1\", \"x2\", \"y2\", \"color\"\n"
            << "If the color is not specified, it is automaticly adjusted to \"Transperant\"!"
            << std::endl;
}

void CommandHandle::print (std::vector<Figure *>& figures) {
    size_t counter = 1;
    for (size_t i = 0; i < figures.size(); i++)
    {
        std::cout << counter++ << ". ";
        figures[i]->print();
    }
    if(counter == 1) {
        std::cout << "There are no avaiable figures!" << std::endl;
    }
}

void CommandHandle::create (std::vector<Figure *>& figures, std::vector<std::string> infoStorage) {
    Figure* newFigure = Factory::getFigure(infoStorage);
    if(newFigure != nullptr) {
        figures.push_back(newFigure);
        std::cout << "Successfully created: ";
        newFigure->print();
    }
}

void CommandHandle::erase (std::vector<Figure *>& figures, std::vector<std::string> infoStorage) {
    size_t erase_index = stoi(infoStorage[0]) - 1;
    if(erase_index < figures.size() && erase_index >= 0) {
        figures.erase(figures.begin() + erase_index);
        std::cout << "Successfully erased figure No: " << infoStorage[0] << "!" << std::endl; 
    } else {
        std::cout << infoStorage[0] << " is not an existing figure!" << std::endl; 
    } 
}

void CommandHandle::translate (std::vector<Figure *>& figures, std::vector<std::string> infoStorage) {
    if(infoStorage.size() == 2
    && Factory::validNumber(infoStorage[0]) 
    && Factory::validNumber(infoStorage[1])) {
        for (size_t i = 0; i < figures.size(); i++)
        {
            figures[i]->translate(stod(infoStorage[0]), stod(infoStorage[1]));
        }
        std::cout << "Successfully translated all figures!" << std::endl;
    } else if(infoStorage.size() == 3
    && Factory::validNumber(infoStorage[0]) 
    && Factory::validNumber(infoStorage[1])
    && Factory::validNumber(infoStorage[2])) {
        size_t translate_index = stoi(infoStorage[0])-1;
        if(translate_index < figures.size() && translate_index >= 0) {
            figures[stoi(infoStorage[0])-1]->translate(stod(infoStorage[1]), stod(infoStorage[2]));
            std::cout << "Successfully translated figure No: " << infoStorage[0] << "!" << std::endl;
        } else {
            std::cout << infoStorage[0] << " is not an existing figure!" << std::endl; 
        }
    } else {
        std::cout << "Wrong use of command! Check help for more info!" << std::endl;
    }
}

void CommandHandle::within (std::vector<Figure *>& figures, std::vector<std::string> infoStorage) {
    size_t counter = 1;
    if(infoStorage[0] == "circle" 
    && Factory::validNumber(infoStorage[1]) 
    && Factory::validNumber(infoStorage[2]) 
    && Factory::validNumber(infoStorage[3])) {
        for (size_t i = 0; i < figures.size(); i++)
        {
            if(figures[i]->within(stod(infoStorage[1]), stod(infoStorage[2]), stod(infoStorage[3]))) {
                std::cout << counter++ << ". ";
                figures[i]->print();
            }
        }
        if(counter == 1) {
            std::cout << "No figures in that range!" << std::endl; 
        }
    } else if(infoStorage[0] == "rectangle"
    && Factory::validNumber(infoStorage[1]) 
    && Factory::validNumber(infoStorage[2]) 
    && Factory::validNumber(infoStorage[3])
    && Factory::validNumber(infoStorage[4])) {
        for (size_t i = 0; i < figures.size(); i++)
        {
            if(figures[i]->within(stod(infoStorage[1]), stod(infoStorage[2]), stod(infoStorage[3]), stod(infoStorage[4]))) {
                std::cout << counter++ << ". ";
                figures[i]->print();
            }
        }
        if(counter == 1) {
            std::cout << "No figures in that range!" << std::endl; 
        }
    } else {
        std::cout << "Not a supported within option or parameters not valid! Check help for more info!" << std::endl;
    }
}