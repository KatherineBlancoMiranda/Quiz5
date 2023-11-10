#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class StudentsInfoManager {

public:

    void showStudentsInfo(const string& fileName) {

        ifstream inputFile;

        inputFile.open(fileName);

        if (!inputFile.is_open()) {

            cerr << "No se pudo abrir el archivo" << endl;
            return;
        }

        string line, information;

        int count = 1;

        while (getline(inputFile, line)) {

            stringstream element(line);

            while (getline(element, information, ',')) {

                if (count == 1) {

                    cout << information << " ";

                }
                if (count == 3) {

                    cout << information << " ";

                }
                if (count == 5) {

                    cout << information << " ";
                    
                }
                if (count == 6) {

                    cout << information << endl;

                }

                count++;

                if (count == 9) {

                    count = 0;
                }

            }

        }

        inputFile.close();

    }

    void getStudentsWithBestScore(const string& fileName) {

        ofstream outputFile;
        ifstream inputFile;

        outputFile.open("students.txt");
        inputFile.open(fileName);

        if (!inputFile.is_open()|| !outputFile.is_open()) {

            cerr << "No se pudo abrir algún archivo" << endl;
            return;

        }

        string line, information;
        int count = 1;

        while (getline(inputFile, line)) {

            stringstream element(line);

            while (getline(element, information, ',')) {

                int score = atoi(information.c_str());

                if (count == 6 && score > 7) {

                    outputFile << line << endl;

                }

                count++;

                if (count == 9) {

                    count = 0;
                }

            }

        }
        outputFile.close();
        inputFile.close();

        cout << "Datos guardados exitosamente" << endl;
    }

    void showInformationByCampus(const string& fileName, string campus) {

        ifstream inputFile;

        inputFile.open(fileName);

        if (!inputFile.is_open()) {

            cerr << "No se pudo abrir el archivo" << endl;
            return;
        }

        string line, information;

        int count = 1;

        while (getline(inputFile, line)) {

            stringstream element(line);

            while (getline(element, information, ',')) {

                if (count == 5 && information == campus) {

                    cout << line << endl;

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

    StudentsInfoManager aFile;

    //aFile.getStudentsWithBestScore("MOCK_DATA.csv");

    //aFile.showStudentsInfo("students.txt");

    aFile.showInformationByCampus("MOCK_DATA.csv", "Llorente");
    
}