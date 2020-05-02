#ifndef COMMANDHANDLE_H
#define COMMANDHANDLE_H

#include "Figure.h"

class CommandHandle {
private:
    static bool exists (std::string fileName);
    static bool empty_File (std::string fileName);
public:
    static void open (std::vector<Figure *>& figures, std::vector<std::string> infoStorage, std::ifstream& r_File, std::string& fileName);
    static void close (std::vector<Figure *>& figures, std::ifstream& r_File, std::string& fileName);
    static void save (std::vector<Figure *>& figures, std::ifstream& r_File, std::string& fileName);
    static void saveas (std::vector<Figure *>& figures, std::vector<std::string> infoStorage, std::ifstream& r_File);
    static void help ();
    static void parameters ();

    static void print (std::vector<Figure *>& figures);
    static void create (std::vector<Figure *>& figures, std::vector<std::string> infoStorage);
    static void erase (std::vector<Figure *>& figures, std::vector<std::string> infoStorage);
    static void translate (std::vector<Figure *>& figures, std::vector<std::string> infoStorage);
    static void within (std::vector<Figure *>& figures, std::vector<std::string> infoStorage);
};

#endif