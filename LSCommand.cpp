// LSCommand.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains functions for the lscommand class.

#include "LSCommand.h"
#include "SimpleFileSystem.h"
#include "MetadataDisplayVisitor.h"

using namespace std;

LSCommand::LSCommand(AbstractFileSystem* afs_) : afs(afs_) {}

void LSCommand::displayInfo() {
	cout << "    ls command displays all files within the file system" << endl;
	cout << "    type ls to display all file names" << endl;
	cout << "    type ls -m to display the metadata info of the files" << endl;
}

int LSCommand::execute(string s) {
	set<string> allFiles = afs->getFileNames();
	// ls
	if (s.compare("") == 0) {
		int fileIndex = 0;
		string prevFileName;
		for (set<string>::iterator it = allFiles.begin(); it != allFiles.end(); ++it) {
			fileIndex += 1;
			if (fileIndex % 2 == 1) {
				cout << *it;
				prevFileName = *it;
			}
			else if (fileIndex % 2 == 0) {
				size_t numSpaces = 20 - prevFileName.length();
				string space = std::string(numSpaces, ' ');
				cout << space << *it << endl;
				prevFileName = *it;
			}
		}
		cout << endl;
	}
	// ls -m
	else if(s.compare("-m") == 0) {
		for (set<string>::iterator it = allFiles.begin(); it != allFiles.end(); ++it) {
			AbstractFileVisitor* visitor = new MetadataDisplayVisitor();
			AbstractFile* file = afs->openFile(*it);
			file->accept(visitor);
			afs->closeFile(file);
			cout << endl;
		}

	}
	else {
		return fail_to_execute;
	}
	return success;
	
}