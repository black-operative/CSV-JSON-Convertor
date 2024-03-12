#pragma once

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
    CSV_JSON() {
        csv_file_path = "";
        json_file_path = "";
    }

    CSV_JSON(const std::string& csv_path, const std::string& json_path, useMode mode) : csv_file_path(csv_path), json_file_path(json_path) {
        switch ((int)mode) {
        case 0:
            //Mode 0 : CSV -> JSON
            file_writer.open(json_file_path);
            file_reader.open(csv_file_path);
            break;

        case 1:
            //Mode 1 : JSON -> CSV
            file_writer.open(csv_file_path);
            file_reader.open(json_file_path);
            break;
        }
    }

    ~CSV_JSON() {
        file_writer.close();
        file_reader.close();
    }

    void changeMode(useMode mode);

    vector<string> CSV_Attributes();

    void CSV_to_JSON();

    void check_JSON();
};