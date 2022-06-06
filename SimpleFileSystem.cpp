// SimpleFileSystem.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
// defines methods of SimpleFileSystem class here

#include "SimpleFileSystem.h"
#include "TextFile.h"
#include <utility>
#include <sstream>
#include <set>
#include <map>
#include <string>
using namespace std;

int SimpleFileSystem::addFile(string filename, AbstractFile* file) {
	if (map.find(filename) != map.end()) {
		return existing_file;
	}
	if (file == nullptr) {
		return ptr_is_nullptr;
	}
	map.insert(pair<string, AbstractFile*>(filename, file) );
	return success;
}

//int SimpleFileSystem::createFile(string filename) {
//	if (map.find(filename) != map.end()) {
//		return existing_file;
//	}
//	string file_name = filename;
//	size_t index = filename.find_last_of(".");
//	filename.replace(index, 1, " ");
//	istringstream iss(filename);
//	string name;
//	string type;
//	iss >> name >> type;
//	if (type == "img") {
//		AbstractFile* imgFile = &ImageFile(name);
//		map.insert(pair<string, AbstractFile*> (file_name,imgFile));
//		return success;
//	}
//	if (type == "txt") {
//		AbstractFile* txtFile = &TextFile(name);
//		map.insert(pair<string, AbstractFile*>(file_name, txtFile));
//		return success;
//	}
//	return not_existing_filetype;
//}

AbstractFile* SimpleFileSystem::openFile(string filename) {
	if (map.find(filename) != map.end()) {
		set<AbstractFile*>::iterator it;
		for (it = openFiles.begin(); it != openFiles.end(); ++it) {
			AbstractFile* a = *it;
			if (a->getName() == filename) {
				return nullptr;
			}
		}
		openFiles.insert(map[filename]);
		return map[filename];
	}
	return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile* file) {
	set<AbstractFile*>::iterator it;
	for (it = openFiles.begin(); it != openFiles.end(); ++it) {
		if (*it == file) {
			openFiles.erase(file);
			return success;
		}
	}
	return not_open;

}

int SimpleFileSystem::deleteFile(string filename) {
	if (map.find(filename) != map.end()) {
		set<AbstractFile*>::iterator it;
		for (it = openFiles.begin(); it != openFiles.end(); ++it) {
			AbstractFile* a = *it;
			if (a->getName() == filename) {
				return file_open;
			}
		}
		map.erase(filename);
		delete map[filename];
		map.erase(filename);
		return success;
	}
	return does_not_exist;
}

set<string> SimpleFileSystem::getFileNames() {
	set<string> fileNames;
	std::map<string, AbstractFile*>::iterator it;

	for (it = map.begin(); it != map.end(); ++it) {
		string name = it->first;
		fileNames.insert(name);
	}
	return fileNames;
}
