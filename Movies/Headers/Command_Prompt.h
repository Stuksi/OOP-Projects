#ifndef CMD_H
#define CMD_H

#include "Event.h"

#include <vector>
#include <fstream>

class CMD {
private:
    static bool exists (std::string);
    static bool empty_file (std::string);
public:
    static void open(std::ifstream&, std::vector<Event>&, std::string&); 
    static void close(std::ifstream&, std::vector<Event>&, std::string&); 
    static void save(std::ifstream&, std::vector<Event>&, std::string); 
    static void saveas(std::ifstream&, std::vector<std::string>, std::vector<Event>&); 
    static void help (); 
    
    static void add_event(std::vector<std::string>, std::vector<Event>&);
    static void free_seats(std::vector<std::string>, std::vector<Event>&); 
    static void access_seats(std::vector<std::string>, std::vector<Event>&, std::vector<int>&, int); 
    static void bookings(std::vector<std::string>, std::vector<Event>&); 
    static void check(std::vector<std::string>, std::vector<Event>&, std::vector<int>&); 
    static void report(std::vector<std::string>, std::vector<Event>&); 
};

#endif