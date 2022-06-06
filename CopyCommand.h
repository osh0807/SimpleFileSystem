// CopyCommand.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
// This file contains declarations of CopyCommand class that runs the command to copy contents of a file to a new file.

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs;

public:
	CopyCommand(AbstractFileSystem*);
	void displayInfo();
	int execute(string s);
};
