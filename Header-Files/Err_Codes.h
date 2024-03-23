#pragma once
#ifndef ERR_CODES
#define ERR_CODES

#include <string>

std::string no_CSV_file  = "Error : No CSV file found \n";
std::string no_JSON_file = "Error : No JSON file found \n";

std::string no_file_reader_init = "Error : Cannot open file for reading \n";
std::string no_file_writer_init = "Error : Cannot open file for writing \n";

std::string no_CSV_attributes = "Error : No Attributes found in CSV file \n";

#endif