// TouchCommand.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains functions for the TouchCommand class.

#include "TouchCommand.h"
#include "PasswordProxy.h"
#include <sstream>

using namespace std;

TouchCommand::TouchCommand(AbstractFileSystem* afs_, AbstractFileFactory* aff_) {
	afs = afs_;
	aff = aff_;
}

void TouchCommand::displayInfo() {
	cout << "Touch can be invoked with the command: touch <filename>" << endl;
}

int TouchCommand::execute(string s) {
	string filename;
	string left;
	istringstream iss(s);
	iss >> filename >> left;

	if (left != "-p") {
		AbstractFile* fileptr = aff->createFile(filename);
		if (fileptr == nullptr || left != "") {
			return fail_to_create;
		}
		else {
			if (afs->addFile(filename, fileptr) == 0) {
				return success;
			}
			else {
				delete fileptr;
				return fail_to_add;
			}
		}
	}
	else {
		string password;
		cout << "enter a pasword" << endl;
		getline(cin, password);
		AbstractFile* fileptr = aff->createFile(filename);
		PasswordProxy* pp = new PasswordProxy(fileptr, password);
		if (fileptr == nullptr) {
			return fail_to_create;
		}
		else {
			if (afs->addFile(filename, pp) == 0) {
				return success;
			}
			else {
				delete fileptr;
				return fail_to_add;
			}

		}

	}
}