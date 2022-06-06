// SimpleFileFactory.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
// studio 18 - simple file factory definitions
#include "SimpleFileFactory.h"
#include <iostream>
#include <sstream>
#include <utility>
using namespace std;

AbstractFile* SimpleFileFactory::createFile(string filename) {
	string file_name = filename;
	size_t index = filename.find_last_of(".");
	if (index > filename.size()) {
		return nullptr;
	}
	filename.replace(index, 1, " ");
	istringstream iss(filename);
	string name;
	string type;
	iss >> name >> type;
	if (type == "img") {
		AbstractFile* imgFile = new ImageFile(name + "." + type);
		return imgFile;
	}
	if (type == "txt") {
		AbstractFile* txtFile = new TextFile(name + "." + type);
		return txtFile;
	}
	return nullptr;
}
