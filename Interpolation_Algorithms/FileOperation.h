#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;

// Read and save file
void readDataFile(string filename, vector<double>& xvalues, vector<double>& yvalues);
//void saveCsv(string outfilename, vector<double> xdata, vector<double> ydata,
//	string headerX, string headerY);

// Analyse input
bool isInputValid(string input);
