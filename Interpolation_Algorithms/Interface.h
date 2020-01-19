#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Interface {
public:
	Interface();
	~Interface();

private:
	vector<double> x_all_;

	// Interface (terminal prompt) functions
	void interfaceIntro();
	void interfaceSelectData();
	void interfaceInput();
	void interfaceInvalid(string message);

	// Analyse data
	void mainOutputAndSave();
};