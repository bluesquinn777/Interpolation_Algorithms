#include "FileOperation.h"

using namespace std;

void readDataFile(string filename, vector<double>& xvalues, vector<double>& yvalues) {
	// Read a CSV data file of two columns (X, Y); First column is x value and second
	// column is y value; First column is added to (vector<double>) xvalues and second
	// column is added to (vector<double>) yvalues.

	// Open file stream
	fstream myFile;
	myFile.open(filename, fstream::in);
	if (myFile.fail()) {
		cerr << filename << endl << "File failed to open..." << endl;
		system("pause");
	}

	string line;
	getline(myFile, line); // Cursor on the first line (header)
	getline(myFile, line);

	while (!myFile.eof()) {
		// Create stream for the line
		stringstream stream(line);

		// Flag to read first col or second col
		// false to read x val, true to read y val
		bool flag = false;
		while (stream.good()) {
			string substr;
			getline(stream, substr, ',');
			if (!flag) xvalues.push_back(atof(substr.c_str()));
			else yvalues.push_back(atof(substr.c_str()));
			flag = !flag;
		}
		getline(myFile, line);
	}
	myFile.close();
}

//void saveVsv(string outfilename, vector<double> xdata, vector<double> ydata,
//	string headerX, string headerY) {
//	// Create a CSV file to (string) outfilename using array of xdata and ydata
//	// in (X, Y) format; First line is header specified by headerX and headerY.
//
//	assert(xdata.size() == ydata.size());
//	fstream myFile;
//	myFile.open(outfilename, fstream::out);
//
//	if (myFile.fail()) {
//		cerr << outfilename << endl << "File failed to open..." << endl;
//		system("pause");
//	}
//	else {
//		cout << endl << "Saving to " << outfilename << " ..." << endl << endl;
//		myFile << headerX + "," + headerY << endl;
//		for (int i = 0; i < xdata.size(); i++) {
//			myFile << xdata[i] << "," << ydata[i] << endl;
//		}
//	}
//	myFile.close();
//}

bool isInputValid(string input) {
	// Check if input is an integer of a set of valid characters x, b.
	int input_int = atoi(input.c_str());

	// If (string) input is not an integer, atoi() will return 0
	if (input_int == 0) {
		stringstream stream(input);
		string substr;
		getline(stream, substr, ' ');
		if (substr == "x" || substr == "b") return true;
		else return false;
	}
	else {
		if (input_int >= 0 && input_int < 10) return true;
		else return false;
	}
}