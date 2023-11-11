#include "studentsinfomanager.h"

void StudentsInfoManager::showStudentsInfo(const string& fileName)
{
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

void StudentsInfoManager::getStudentsWithBestScore(const string& fileName)
{
    ofstream outputFile;
    ifstream inputFile;

    outputFile.open("students.txt");
    inputFile.open(fileName);

    if (!inputFile.is_open() || !outputFile.is_open()) {

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
}

void StudentsInfoManager::showInformationByCampus(const string& fileName, string campus)
{
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

string StudentsInfoManager::getStudentsScores(const string& fileName)
{
    ifstream inputFile;

    inputFile.open(fileName);

    if (!inputFile.is_open()) {

        cerr << "No se pudo abrir el archivo" << endl;
    }

    string line, information, text;

    int count = 1;

    while (getline(inputFile, line)) {

        stringstream element(line);

        while (getline(element, information, ',')) {

            if (count == 6 || count == 8) {

                text += information + " ";
            }

            count++;

            if (count == 9) {

                text += information + " ";
                count = 0;
            }
        }
    }
    inputFile.close();
    return text;
}
