// DisplayCommand.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
// This file contains declarations of DisplayCommand class that runs the command to display the contents of a file

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs;

public:
	DisplayCommand(AbstractFileSystem*);
	void displayInfo();
	int execute(string s);
};
