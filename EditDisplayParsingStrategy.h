//EditDisplayParsingStrategy.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the parsing strategy for cat + ds commands.

#pragma once
#include "AbstractParsingStrategy.h"

class EditDisplayParsingStrategy : public AbstractParsingStrategy {
public:
	vector<string> parse(string);
	void displayInfo();
};