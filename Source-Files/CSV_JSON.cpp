#include "../Header-Files/CSV_JSON.h"
#include "../Header-Files/Err_Codes.h"

vector<string> CSV_JSON::CSV_Attributes() {
    vector<string> Attributes;

    if (this->csv_file_path.empty()) {
        Attributes.clear();
        return Attributes;
    }

    ifstream csv_file(this->csv_file_path);
    string attr;

    //Line 1 of CSV file containing all attributes
    getline(csv_file, attr);

    //Iterate over attributes string
    string str;
    for (char ch : attr) {
        //Add characters to container while no comma encountered
        if (ch != ',') {
            str += ch;
        }
        //Pushing container characters into attribute vector if encountering comma
        else {
            Attributes.emplace_back(str);
            //clearing container for next attribute
            str.clear();
        }
    }

    //Inserting final attribute after last comma in string
    if (!str.empty()) { Attributes.emplace_back(str); }

    csv_file.close();
    return Attributes;
}

void CSV_JSON::changeMode(useMode mode) {
    this->file_writer.close();
    this->file_reader.close();

    switch ((int)mode) {
    case 0:
        //Mode 0 : CSV -> JSON
        this->file_writer.open(json_file_path);
        this->file_reader.open(csv_file_path);
        break;


    case 1:
        //Mode 1 : JSON -> CSV
        this->file_writer.open(csv_file_path);
        this->file_reader.open(json_file_path);
        break;
    }
}

void CSV_JSON::CSV_to_JSON() {
    vector<string> file_attributes = CSV_Attributes();

    //Check if file path is empty
    if (this->csv_file_path.empty()) {
        std::cerr << no_CSV_file;
        return;
    }

    //Check if file path can't be opened
    if (!this->file_writer.is_open()) { 
        std::cerr << no_file_reader_init; 
        return;
    }

    //Check if csv file contains attributes
    if (file_attributes.empty()) { 
        std::cerr << no_CSV_attributes; 
        return;
    }

    string line, temp;
    stringstream sBuilder;
    
    int lineCount = 0, objCount = 1;
    while (getline(this->file_reader, temp)) { lineCount++; }
    lineCount--;

    cout << "Line count : " << lineCount << "\n";
    this->file_reader.clear();
    this->file_reader.seekg(0, std::ios::beg);

    this->file_writer << "[";

    getline(this->file_reader, temp);

    //Iterate though entire CSV file to create a Vector of JSON formatted String builder objects
    while (getline(this->file_reader, line)) {
        stringstream temp(line);
        vector<string> values;
        string str;

        while (getline(temp, str, ',')) { values.emplace_back(str); }

        if (values.size() != file_attributes.size()) {
            std::cerr << "Err ! Number of values in a row does not match number of attributes\n";
            continue;
        }

        sBuilder.str("");
        sBuilder << "\n\t{\n";

        for (int i = 0; i < file_attributes.size(); ++i) {
            //Push object attribute and value into string builder
            sBuilder << "\t\t\"" << file_attributes[i] << "\" : \"" << values[i] << "\"";

            //Push "," between attribute : value pairs until end of attributes vector
            if (i < file_attributes.size() - 1) { sBuilder << ",\n"; }
        }
        sBuilder << "\n\t}";

        this->file_writer << sBuilder.str();

        if (objCount < lineCount) { this->file_writer << ",\n"; }
        else { this->file_writer << "\n"; }
        objCount++;
    }

    this->file_writer << "]";   
}

void CSV_JSON::check_JSON() {
    if (this->json_file_path.empty()) {
        std::cerr << "Error : No JSON file found \n";
    }

    if (!this->file_reader.is_open()) {
        std::cerr << "Error : Cannot open JSON file \n";
    }
}