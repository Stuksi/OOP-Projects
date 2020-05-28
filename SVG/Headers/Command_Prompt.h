#ifndef COMMAND_PROMPT_H
#define COMMAND_PROMPT_H

#include "Shape.h"
#include <fstream>

/**
 * @fn bool exists()
 * By a given string(file name), find if the file exists in the current directory.
 * @fn bool empty_file()
 * Checks whether the file is empty.
 * @fn void open()
 * Opens a file, and reads its information to the system, ready to be modified.
 * @fn void close()
 * Closes the opened file and removes the information of it from the system.
 * @fn void save()
 * Saves the current information in the system to the same file it was read from.
 * @fn void saveas()
 * Saves the current information in the system to a specific file.
 * @fn void help()
 * Outputs a helper menu, to show the available user commands.
 * @fn void parameters()
 * Show information about all the supported shapes.
 */

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