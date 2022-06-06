//ChmodCommand.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//this file defines each function of ChmodCommand
//(additional file for extra credit)
#include "ChmodCommand.h"
#include <sstream>
using namespace std;

ChmodCommand::ChmodCommand(AbstractFileSystem* afs_) {
	afs = afs_;
}

void ChmodCommand::displayInfo() {
	cout << "Chmod can be invoked with the command: chmod <filename> - or +" << endl;
}

int ChmodCommand::execute(string s) {
	istringstream iss(s);		//wrap input into stringstream and extract filename and suffix showing - or +
	string filename;
	string mode;
	iss >> filename >> mode;
	AbstractFile* fileptr = afs->openFile(filename);
	if (fileptr == nullptr) {		//close file if it does not exist in filesystem
		afs->closeFile(fileptr);
		return fail_to_open;
	}
	else {
		fileptr->chmod(mode);		//call member function chmod() with the suffix for each file
		return success;
	}
}