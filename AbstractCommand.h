#pragma once
//AbstractCommand.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file declares the AbstractCommand interface, which is inherited by all commands in this program.

#include <string>
using namespace std;

class AbstractCommand {
public: 
	virtual int execute(string s) = 0;
	virtual void displayInfo() = 0;
	virtual ~AbstractCommand() = default;

};

