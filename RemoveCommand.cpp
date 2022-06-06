// RemoveCommand.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains functions for the RemoveCommand class.

#include "RemoveCommand.h"
#include "SimpleFileSystem.h"
#include "MetadataDisplayVisitor.h"


RemoveCommand::RemoveCommand(AbstractFileSystem* afs_) : afs(afs_) {}

void RemoveCommand::displayInfo() {
	cout << "    rm command removes the file with the provided name from the file system" << endl;
	cout << "    type rm and a file name to remove that file" << endl;
}

int RemoveCommand::execute(string s) {
	set<string> allFiles = afs->getFileNames();
	int deleteResult = afs->deleteFile(s);
	if (allFiles.find(s) == allFiles.end()) {
		cout << "The file does not exist" << endl;
		return does_not_exist;
	}
	else if (s == "") {
		cout << "Please enter a file name to delete" << endl;
	}
	else if (deleteResult == file_open) {
		cout << "The file is open. You must close the file first to delete" << endl;
		return file_open;
	}
	afs->deleteFile(s);
	return success;
}


