#pragma once
#ifndef CSV_HEADER
#define CSV_HEADER

#include "Header.h"

class CSV_JSON {
private:
    string csv_file_path;
    string json_file_path;
    ofstream file_writer;
    ifstream file_reader;
    vector<string> attributes;
    useMode mode = CSV_TO_JSON;


public:
    CSV_JSON();

    CSV_JSON(const std::string&, const std::string&, useMode);

    ~CSV_JSON();

    void changeMode(useMode);

    vector<string> CSV_Attributes();

    void CSV_to_JSON();

    void check_JSON();
};

#endif