// RemoveCommand.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the RemoveCommand class that removes a file from the file system.

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

using namespace std;

class RemoveCommand : public AbstractCommand {
public:
	RemoveCommand(AbstractFileSystem* afs);
	virtual int execute(string s);
	virtual void displayInfo();

private:
	AbstractFileSystem* afs;
};
