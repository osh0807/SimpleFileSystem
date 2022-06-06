// DisplayCommand.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
// This file contains definitions of DisplayCommand class that runs the command to display the contents of a file.

#include "DisplayCommand.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
#include <sstream>
using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* afs_) {
	afs = afs_;
}

void DisplayCommand::displayInfo() {
	cout << "Display can be invoked with the command: ds <filename> which gives formatted contents or with the command: ds <filename> -d which gives the unformatted contents." << endl;
}

int DisplayCommand::execute(string s) {
	istringstream iss(s);

	string filename;
	string second;
	iss >> filename >> second;

	set<string> files = afs->getFileNames();
	if (files.find(filename) == files.end()) {
		return does_not_exist;
	}

	AbstractFile* fileptr = afs->openFile(filename);
	if (fileptr == nullptr) {
		return fail_to_open;
	}
	//if (s.find('-d') == string::npos) { // no -d present
	if(second != "-d"){
		AbstractFileVisitor* v = new BasicDisplayVisitor();
		fileptr->accept(v);
		afs->closeFile(fileptr);
	}
	else { // -d present 
		vector<char> contents = fileptr->read();
		for (unsigned int i = 0; i < contents.size(); i++) {
			if (contents[i] == '\n') {
				cout << endl;
			}
			else {
				cout << contents[i];
			}
		}
		cout << endl;
		afs->closeFile(fileptr);
	}
	return success;
}