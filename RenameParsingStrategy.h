// RenameParsingStrategy.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the RenameParsingStrategy class that parses the input so that we can run the combination of commands.

#pragma once
#include "AbstractParsingStrategy.h"

class RenameParsingStrategy : public AbstractParsingStrategy {
public:
	vector<string> parse(string);
	void displayInfo();
};

