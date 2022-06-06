//ImageFile.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the functions used for image files.

#pragma once
#include "AbstractFile.h"


class ImageFile : public AbstractFile {
public:
	ImageFile(string s);
	unsigned int getSize();
	string getName();
	int write(vector<char> str);
	int append(vector<char> str);
	vector<char> read();
	void accept(AbstractFileVisitor*);
	int coordToIndex(int x, int y);
	AbstractFile* clone(string name);
	void chmod(string s);

private:
	string name;
	vector<char> contents;
	char size;
	bool writable = true;
};