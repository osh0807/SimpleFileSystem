#pragma once
//AbstractParsingStrategy.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file declares the base class AbstractParsingStrategy which is used by EditDisplayParsingStrategy and RenameParsingStrategy
#include <string>
#include <vector>
using namespace std;

class AbstractParsingStrategy {
public: 
	virtual vector<string> parse(string) = 0;
	virtual void displayInfo() = 0;
};

