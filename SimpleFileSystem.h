// SimpleFileSystem.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
// This file contains declarations of SimpleFileSystem class

#pragma once
#include "AbstractFileSystem.h"
#include "ImageFile.h"
#include <map>
#include <set>
// declaration of SimpleFileSystem class goes here

class SimpleFileSystem : public AbstractFileSystem {
public:
	map<string, AbstractFile*> map;
	set<AbstractFile*> openFiles;
	int addFile(string filename, AbstractFile* file);
	//int createFile(string filename);
	AbstractFile* openFile(string filename);
	int deleteFile(string filename);
	int closeFile(AbstractFile* file);
	set<string> getFileNames();

private:

};
