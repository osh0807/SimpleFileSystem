#pragma once
//AbstractFileSystem.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file declares the base class AbstractFileSystem which is used by SimpleFileSystem
#include "AbstractFile.h"
#include <set>

using namespace std;
// declaration of the interface all file systems provide goes here

class AbstractFileSystem {
public:
	virtual int addFile(string filename, AbstractFile* file) = 0;
	virtual int deleteFile(string filename) = 0;
	virtual AbstractFile* openFile(string filename) = 0;
	virtual int closeFile(AbstractFile* file) = 0;
	virtual set<string> getFileNames() = 0;

private:
};
