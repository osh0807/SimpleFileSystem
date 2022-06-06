#pragma once
//ChmodCommand.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file declares ChmodCommand which publicly inherits AbstractCommand
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"

class ChmodCommand : public AbstractCommand {
private:
	AbstractFileSystem* afs;

public:
	ChmodCommand(AbstractFileSystem*);
	void displayInfo();
	int execute(string s);
};
