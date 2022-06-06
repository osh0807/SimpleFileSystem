// RenameParsingStrategy.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains functions for the RenameParsingStrategy class.

#include "RenameParsingStrategy.h"
#include <iostream>
#include <sstream>

using namespace std;

vector<string> RenameParsingStrategy::parse(string s) {
	istringstream iss(s);
	string prevName;
	string newName;
	iss >> prevName >> newName;
	vector<string> output;
	output.push_back(prevName + " " + newName);
	output.push_back(prevName);
	return output;
}

void RenameParsingStrategy::displayInfo() {
	cout << "Rename can be invoked with: rn <existing_file> <new_name_with_no_extension>" << endl;

}

