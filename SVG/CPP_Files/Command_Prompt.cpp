#include "..\Headers\Command_Prompt.h"
#include "..\Headers\Rectangle.h"
#include "..\Headers\Circle.h"
#include "..\Headers\Factory.h"

#include <fstream>

/**
 * @fn bool CMD::exists()
 * By a given string(file name), find if the file exists in the current directory.
 * (Stack Overflow)
 * @fn bool CMD::empty_file()
 * Checks whether the file is empty.
 * (Stack Overflow)
 * @fn void CMD::open()
 * Opens a file, and reads its information to the system, ready to be modified.
 * @fn void CMD::close()
 * Closes the opened file and removes the information of it from the system.
 * @fn void CMD::save()
 * Saves the current information in the system to the same file it was read from.
 * @fn void CMD::saveas()
 * Saves the current information in the system to a specific file.
 * @fn void CMD::help()
 * Outputs a helper menu, to show the available user commands.
 * @fn void CMD::parameters()
 * Show information about all the supported shapes.
 */


// Defining static members of factory.
std::string Factory::top_file;
std::string Factory::bottom_file;

// Stack Overflow
bool CMD::exists(std::string file_name) {
    std::fstream file(file_name);
    return file.good();
}

// Stack Overflow
bool CMD::empty_file(std::string file_name) {
    std::fstream file(file_name);
    return file.peek() == std::ifstream::traits_type::eof();
}

void CMD::open (std::vector<Shape *>& shapes, std::ifstream& r_file, std::string& file_name) {
    if(!r_file.is_open() && exists(file_name)) {
        Factory::bottom_file = "";
        Factory::top_file = "";
        r_file.open(file_name);
        if(!empty_file(file_name)){
            r_file >> shapes;
        }
        std::cout << file_name << " opened successfully!" << std::endl;
    } else {
        std::cout << file_name << " does not exist or is already opened!" << std::endl;
        file_name = "";
    }
}

void CMD::close (std::vector<Shape *>& shapes, std::ifstream& r_file, std::string& file_name) {
    if(r_file.is_open()) {
        shapes.clear();
        r_file.close();
        std::cout << file_name << " closed successfully!" << std::endl;
        file_name = "";
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
} 

void CMD::save (std::vector<Shape *>& shapes, std::ifstream& r_file, std::string& file_name) {
    if(r_file.is_open()) {
        std::ofstream w_file(file_name);
        w_file << shapes;
        w_file.close();
        std::cout << "Information saved successfully to " << file_name << "!" << std::endl;
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
}

void CMD::saveas (std::vector<Shape *>& shapes, std::vector<std::string> info_storage, std::ifstream& r_file) {
    if(r_file.is_open()) {
        if(!exists(info_storage[0])){
            std::ofstream w_file(info_storage[0]);
            w_file << shapes;
            w_file.close();
            std::cout << "Information saved successfully to " << info_storage[0] << "!" << std::endl;
        }else {
            std::cout << "The file name already exists!" << std::endl;
        }
    } else {
        std::cout << "There isn't an opened file!" << std::endl;
    }
}

void CMD::help () {
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

void CMD::parameters () {
    std::cout << "The following parameters for the shapes are supported:\n"
            << "   Rectangle     \"x\", \"y\", \"width\", \"height\", \"rx\", \"ry\", \"color\"\n"
            << "   Circle        \"cx\", \"cy\", \"r\", \"color\"\n"
            << "   Line          \"x1\", \"y1\", \"x2\", \"y2\", \"color\"\n"
            << "If the color is not specified, it is automaticly adjusted to \"Transperant\"!\n Every shape supports a stroke colour and a stroke-width value!"
            << std::endl;
}

void CMD::print (std::vector<Shape *>& shapes) {
    size_t counter = 1;
    for (size_t i = 0; i < shapes.size(); i++)
    {
        std::cout << counter++ << ". ";
        shapes[i]->print();
    }
    if(counter == 1) {
        std::cout << "There are no avaiable shapes!" << std::endl;
    }
}

void CMD::create (std::vector<Shape *>& shapes, std::vector<std::string> info_storage) {
    Shape* newShape = Factory::get_shape(info_storage);
    if(newShape != nullptr) {
        shapes.push_back(newShape);
        std::cout << "Successfully created: ";
        newShape->print();
    } else {
        std::cout << "Error while creating shape!" << std::endl;
    }
}

void CMD::erase (std::vector<Shape *>& shapes, std::vector<std::string> info_storage) {
    size_t erase_index = stoi(info_storage[0]) - 1;
    if(erase_index < shapes.size() && erase_index >= 0) {
        shapes.erase(shapes.begin() + erase_index);
        std::cout << "Successfully erased Shape No: " << info_storage[0] << "!" << std::endl; 
    } else {
        std::cout << info_storage[0] << " is not an existing Shape!" << std::endl; 
    } 
}

void CMD::translate (std::vector<Shape *>& shapes, std::vector<std::string> info_storage) {
    if(info_storage.size() == 2) {
        for (size_t i = 0; i < shapes.size(); i++)
        {
            shapes[i]->translate(stod(info_storage[0]), stod(info_storage[1]));
        }
        std::cout << "Successfully translated all shapes!" << std::endl;
    } else if(info_storage.size() == 3) {
        size_t translate_index = stoi(info_storage[0])-1;
        if(translate_index < shapes.size() && translate_index >= 0) {
            shapes[stoi(info_storage[0])-1]->translate(stod(info_storage[1]), stod(info_storage[2]));
            std::cout << "Successfully translated Shape No: " << info_storage[0] << "!" << std::endl;
        } else {
            std::cout << info_storage[0] << " is not an existing Shape!" << std::endl; 
        }
    } else {
        std::cout << "Wrong use of command! Check help for more info!" << std::endl;
    }
}

void CMD::within (std::vector<Shape *>& shapes, std::vector<std::string> info_storage) {
    size_t counter = 1;
    if(info_storage[0] == "circle") {
        Circle circle(stod(info_storage[1]), stod(info_storage[2]), stod(info_storage[3]), Transperant);
        for (size_t i = 0; i < shapes.size(); i++)
        {
            if(shapes[i]->within(circle)) {
                std::cout << counter++ << ". ";
                shapes[i]->print();
            }
        }
        if(counter == 1) {
            std::cout << "No shapes in that range!" << std::endl; 
        }
    } else if(info_storage[0] == "rectangle") {
        Rectangle rectangle(stod(info_storage[1]), stod(info_storage[2]), stod(info_storage[3]), stod(info_storage[4]), Transperant);
        for (size_t i = 0; i < shapes.size(); i++)
        {
            if(shapes[i]->within(rectangle)) {
                std::cout << counter++ << ". ";
                shapes[i]->print();
            }
        }
        if(counter == 1) {
            std::cout << "No shapes in that range!" << std::endl; 
        }
    } else {
        std::cout << "Not a supported within option or parameters not valid! Check help for more info!" << std::endl;
    }
}