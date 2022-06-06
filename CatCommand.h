#pragma once
//CatCommand.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file declares CatCommand which publicly inherits AbstractCommand

#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

//enumeration used to subtract commandline from input
enum Cathelper {
	subtractingwq = 4
};

class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs;

public:
	CatCommand(AbstractFileSystem* afs);
	int execute(string s);
	void displayInfo();
};
