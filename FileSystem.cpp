// FileSystem.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains the 'main' function. Program execution begins and ends there.


#include "TouchCommand.h"
#include "SimpleFileSystem.h"
#include "SimpleFileFactory.h"
#include "CommandPrompt.h"
#include "LSCommand.h"
#include "RemoveCommand.h"
#include "DisplayCommand.h"
#include "CatCommand.h"
#include "CopyCommand.h"
#include "MacroCommand.h"
#include "RenameParsingStrategy.h"
#include "EditDisplayParsingStrategy.h"

int main()
{

	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();
	AbstractCommand* tc = new TouchCommand(sfs, sff);
	AbstractCommand* ls = new LSCommand(sfs);
	AbstractCommand* rm = new RemoveCommand(sfs);
	AbstractCommand* cat = new CatCommand(sfs);
	AbstractCommand* ds = new DisplayCommand(sfs);
	AbstractCommand* copy = new CopyCommand(sfs);

	CommandPrompt cp = CommandPrompt();
	cp.setFileFactory(sff);
	cp.setFileSystem(sfs);
	cp.addCommand("touch", tc);
	cp.addCommand("ls", ls);
	cp.addCommand("rm", rm);
	cp.addCommand("cat", cat);
	cp.addCommand("ds", ds);
	cp.addCommand("cp", copy);

	//Macro Command 1 
	MacroCommand* mc = new MacroCommand(sfs);
	RenameParsingStrategy* rps = new RenameParsingStrategy;
	AbstractCommand* cpc = new CopyCommand(sfs);
	AbstractCommand* rmc = new RemoveCommand(sfs);
	mc->setParseStrategy(rps);
	mc->addCommand(cpc);
	mc->addCommand(rmc);
	cp.addCommand("rn", mc);

	//Additional Macro Command
	MacroCommand* admc = new MacroCommand(sfs);
	EditDisplayParsingStrategy* edps = new EditDisplayParsingStrategy;
	AbstractCommand* cps = new CatCommand(sfs);
	AbstractCommand* dps = new DisplayCommand(sfs);
	admc->setParseStrategy(rps);
	admc->addCommand(cps);
	admc->addCommand(dps);
	cp.addCommand("catds", admc);

	cp.run();

	return 0;
}