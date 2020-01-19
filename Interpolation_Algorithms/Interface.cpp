#include "Lagrange.h"
#include "Interface.h"
#include "FileOperation.h"

using namespace std;

Interface::Interface() {
	//initialise x_all_
	x_all_ = {};

	interfaceIntro();
}

Interface::~Interface() {}

void Interface::interfaceIntro() {
	system("CLS");
	cout << endl << "----------------------------------------" << endl
		<< " INTERPOLATION ALGORITHMS IMPLEMENTATION" << endl
		<< "----------------------------------------" << endl << endl;

	cout << "---------------------------------------" << endl
		<< " This software is designed to implement" << endl
		<< " two different interpolation algorithms" << endl
		<< "---------------------------------------" << endl << endl;

	cout << "---------------------------------------" << endl
		<< " Data Source: Random value from Qiuchen" << endl
		<< "---------------------------------------" << endl << endl;

	cout << "Would you like to continue? (y/n)" << endl;
	cout << " >> ";
	char select;
	cin >> select;
	switch (select)
	{
	case 'y': break;
	case 'n': exit(0);
	default: interfaceIntro();
	}

	interfaceSelectData();
}

void Interface::interfaceSelectData() {
	// Select data file from Data folder.
	system("CLS");
	cin.clear();
	cout << endl << " Select Data:" << endl << endl;
	cout << " 1: Random X and Y value" << endl
		<< " b: Back" << endl
		<< " x: Exit" << endl << endl 
		<< " >> ";
	string select;
	cin >> select;

	// String to char
	char* select_char = new char[1];
	if (select.size() != 1) *select_char = '#';
	else copy(select.begin(), select.end(), select_char);

	switch (*select_char)
	{
	case '1': interfaceInput(); break;
	case 'b': system("CLS"); cin.ignore(); interfaceIntro(); break;
	case 'x': exit(0);
	default: interfaceInvalid(""); interfaceSelectData();
	}
	delete[] select_char;
}

void Interface::interfaceInvalid(string message) {
	// Ignore current line in cin stream up to '\n'
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("CLS");
	cout << endl << " Invalid Selection" << endl << endl;
	cout << "------------------------------" << endl;
	cout << message << endl << endl;
	cout << " Press enter to return..." << endl;
	cin.get(); // Only receive one character.
}

void Interface::interfaceInput() {
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("CLS");
	cout << endl << " Enter a x value you want to interpolate:" << endl << endl;
	
	bool repeat = true;

	while (repeat) {
		cout << endl << "Enter >> ";
		string select;
		cin >> select;

		double select_db = atof(select.c_str());
		if (select_db == 0) {
			interfaceInvalid("Please enter a number (float or integer)");
			interfaceInput();
		}
		else x_all_.push_back(select_db);

		// Sort and remove duplicated value
		// unique() will return a vector with processed value
		// erase() will remove all elements after unique() until last element
		sort(x_all_.begin(), x_all_.end());
		x_all_.erase(unique(x_all_.begin(), x_all_.end()), x_all_.end());

		cout << endl;
		// for each element in (vector) x_all_
		for (double xx : x_all_) {
			cout << " " << xx << " ";
		}
		cout << "entered." << endl << endl;

		// Clear all stuff in cin stream
		cin.clear();
		cin.ignore();

		char select2;
		cout << "Would you like to enter another value? (y/n)" << endl
			<< " >> ";
		cin >> select2;
		switch (select2)
		{
		case 'y': repeat = true; break;
		case 'n': repeat = false; break;
		default: interfaceInvalid(""); interfaceInput();
		}
	}
	mainOutputAndSave();
}

void Interface::mainOutputAndSave() {
	// Function to output interpolated data
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	system("CLS");

	vector<double> x_vals, y_vals, res_vals;

	for (double xx : x_all_) {
		string filename = "./data/random-value-xy.csv";
		readDataFile(filename, x_vals, y_vals);
		LagrangeInterpolation Interpo(xx);
		double* temp = new double;
		*temp = Interpo.lineExtrapolationSingleY(xx, x_vals, y_vals);
		res_vals.push_back(*temp);
		cout << endl << xx << " : " << *temp << endl;
		delete temp;
	}
	cout << endl;
	system("pause");
	interfaceInput();
}