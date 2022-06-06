// MacroCommand.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the MacroCommand class that manages combinations of other commands.

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include "AbstractParsingStrategy.h"

class MacroCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs;
	vector<AbstractCommand*> vCmds;
	AbstractParsingStrategy* aps;

public:
	MacroCommand(AbstractFileSystem*);
	void displayInfo();
	int execute(string s);
	void addCommand(AbstractCommand*);
	void setParseStrategy(AbstractParsingStrategy*);
};
