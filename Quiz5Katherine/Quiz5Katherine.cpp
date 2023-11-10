#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class FileManager {

public:

    void showStudentsInfo(const string& fileName) {

        ifstream inputFile;

        inputFile.open(fileName);

        if (!inputFile.is_open()) {

            cerr << "No se pudo abrir el archivo" << endl;

        }

        string line, subject;

        int count = 1;

        while (getline(inputFile, line)) {

            stringstream element(line);

            while (getline(element, subject, ',')) {

                if (count == 1) {

                    cout << subject << " ";

                }
                if (count == 3) {

                    cout << subject << " ";

                }
                if (count == 5) {

                    cout << subject << " ";
                    
                }
                if (count == 6) {

                    cout << subject << endl;

                }

                count++;

                if (count == 9) {

                    count = 0;
                }

            }

        }

        inputFile.close();

    }

};

int main()
{

    FileManager file;

    file.showStudentsInfo("MOCK_DATA.csv");
    
}