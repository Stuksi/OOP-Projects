#ifndef COMMAND_PROMPT_H
#define COMMAND_PROMPT_H

#include "Shape.h"
#include <fstream>

class CMD {
private:
    static bool exists (std::string file_name);
    static bool empty_file (std::string file_name);
public:
    static void open (std::vector<Shape *>& shapes, std::vector<std::string> info_storage, std::ifstream& r_file, std::string& file_name);
    static void close (std::vector<Shape *>& shapes, std::ifstream& r_file, std::string& file_name);
    static void save (std::vector<Shape *>& shapes, std::ifstream& r_file, std::string& file_name);
    static void saveas (std::vector<Shape *>& shapes, std::vector<std::string> info_storage, std::ifstream& r_file);
    static void help ();
    static void parameters ();

    static void print (std::vector<Shape *>& shapes);
    static void create (std::vector<Shape *>& shapes, std::vector<std::string> info_storage);
    static void erase (std::vector<Shape *>& shapes, std::vector<std::string> info_storage);
    static void translate (std::vector<Shape *>& shapes, std::vector<std::string> info_storage);
    static void within (std::vector<Shape *>& shapes, std::vector<std::string> info_storage);
};
#endif