#pragma once
#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::cout;
using std::cin;
using std::endl;
using std::stringstream;

enum useMode {
    CSV_TO_JSON,
    JSON_TO_CSV
};

#endif