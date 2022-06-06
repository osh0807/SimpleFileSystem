// LSCommand.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the ls command (lists names of files).

#pragma once
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

using namespace std;

class LSCommand : public AbstractCommand {
public:
	LSCommand(AbstractFileSystem* afs);
	virtual int execute(string s);
	virtual void displayInfo();

private:
	AbstractFileSystem* afs;
};