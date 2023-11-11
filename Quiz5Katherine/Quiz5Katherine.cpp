#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "studentsinfomanager.h"

using namespace std;

int main()
{

    StudentsInfoManager aFile;

    aFile.getStudentsWithBestScore("MOCK_DATA.csv");

    aFile.showStudentsInfo("students.txt");

    cout << endl;

    aFile.showInformationByCampus("MOCK_DATA.csv", "Llorente");

    aFile.getStudentsScores("MOCK_DATA.csv");
    
}