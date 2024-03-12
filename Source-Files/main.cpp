#include "../Header-Files/Header.h"
#include "../Header-Files/CSV_JSON.h"

int main(int argc, char* argv[]) {
    string csv_file = "D:\\College\\stash\\C-C++ Builds\\Data-Files\\Data.csv";
    string json_file = "D:\\College\\stash\\C-C++ Builds\\Data-Files\\Data.json";
    
    CSV_JSON* app = new CSV_JSON(csv_file, json_file, CSV_TO_JSON);
    vector<string> Attributes = app->CSV_Attributes();

    for (string str : Attributes) { cout << str << endl; }
    app->CSV_to_JSON();

    delete app;

    getchar();

	return 0;
}