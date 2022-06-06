// CopyCommand.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
// This file contains definitions of CopyCommand class that runs the command to copy contents of a file to a new file.

#include "CopyCommand.h"
#include <iostream>
#include <sstream>
using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* afs_) {
	afs = afs_;
}

void CopyCommand::displayInfo() {
	cout << "Copy can be invoked with the command: cp <file_to_copy> <new_name_with_no_extension>" << endl;
}

int CopyCommand::execute(string s) {
	istringstream iss(s);

	string filename;
	string filenameNoP;
	string copyname;
	iss >> filename >> copyname;
	//whether file exists 
	set<string> files = afs->getFileNames();
	if (files.find(filename) == files.end()) {
		return does_not_exist;
	}
	
	//get file extension
	filenameNoP = filename;
	size_t index = filenameNoP.find_last_of(".");
	filenameNoP.replace(index, 1, " ");
	istringstream iss2(filenameNoP);
	string name;
	string type;
	iss2 >> name >> type;
	string copyfileExt = copyname + '.' + type;

	// whether a name to be copied to is given
	if (copyname == "") {
		return does_not_exist;
	}
	// whether file to be copied to exists or not
	if (files.find(copyfileExt) != files.end()) {
		return does_not_exist;
	}

	//make deep copy of file
	AbstractFile* fileptr = afs->openFile(filename);
	AbstractFile* copyFile = fileptr->clone(copyfileExt);
	afs->closeFile(fileptr);
	if (afs->addFile(copyfileExt, copyFile) == 0) {
		return success;
	}
	else {
		return fail_to_add;
	}
}