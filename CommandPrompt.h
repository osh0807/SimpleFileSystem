#pragma once
//CommandPrompt.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file declares CommandPrompt class
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <map>
#include <string>

using namespace std;

class CommandPrompt {
public:
	CommandPrompt();
	void setFileSystem(AbstractFileSystem*);
	void setFileFactory(AbstractFileFactory*);
	int addCommand(string, AbstractCommand*);
	int run();
private:
	map<string, AbstractCommand*> sToAc;
	AbstractFileSystem* afs;
	AbstractFileFactory* aff;
protected:
	void listCommands();
	string prompt();
};

