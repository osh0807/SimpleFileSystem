//EditDisplayParsingStrategy.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains functions for the EditDisplayParsingStrategy class - parses strategy for cat + ds commands.

#include "EditDisplayParsingStrategy.h"

#include <iostream>
#include <sstream>

using namespace std;

vector<string> EditDisplayParsingStrategy::parse(string s) {
	istringstream iss(s);
	string filename;
	string ext;
	string extra;
	iss >> filename;
	iss >> ext;
	iss >> extra;
	vector<string> output;
	output.push_back(s);
	output.push_back(filename);
	return output;
}

void EditDisplayParsingStrategy::displayInfo() {
	cout << "Cat + ds can be invoked with: catds <existing_file>" << endl;

}