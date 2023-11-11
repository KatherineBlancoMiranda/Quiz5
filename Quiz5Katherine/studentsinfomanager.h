#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class StudentsInfoManager {

public:

	void showStudentsInfo(const string& fileName);

	void getStudentsWithBestScore(const string& fileName);

	void showInformationByCampus(const string& fileName, string campus);

	string getStudentsScores(const string& fileName);

};