// TouchCommand.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the TouchCommand class that facilitates the command to create a new file.

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

class TouchCommand: public AbstractCommand {
private:
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;

public:
	TouchCommand(AbstractFileSystem*, AbstractFileFactory*);
	void displayInfo();
	int execute(string s);
};
