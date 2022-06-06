// MacroCommand.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains functions for the MacroCommand class.

#include "MacroCommand.h"

using namespace std;

MacroCommand::MacroCommand(AbstractFileSystem* afs_):
	afs(afs_), aps(nullptr){}

int MacroCommand::execute(string s) {
	vector<string> cmdnames = aps->parse(s);
	for (unsigned int i = 0; i < vCmds.size(); i++) {
		int result = vCmds[i]->execute(cmdnames[i]);
		if (result != success) {
			return fail_to_execute_macro;
		}
	}
	return success;
}

void MacroCommand::displayInfo() {

	if (aps != nullptr) {
		aps->displayInfo();
	}
	else {
		cout << "no macro commands exist" << endl;
	}
}

void MacroCommand::addCommand(AbstractCommand* newCmd) {
	vCmds.push_back(newCmd);
}

void MacroCommand::setParseStrategy(AbstractParsingStrategy* aps_) {
	aps = aps_;
}
