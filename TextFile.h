// TextFile.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the Textfile class.

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "AbstractFile.h"

using namespace std;


class TextFile : public AbstractFile {
public:
	TextFile(string name);
	unsigned int getSize();
	string getName();
	int write(vector<char> str);
	int append(vector<char> newS);
	vector<char> read();
	void accept(AbstractFileVisitor*);
	AbstractFile* clone(string name);
	void chmod(string s);

protected:
	vector<char> contents;
	string name_;
	bool writable = true;
};
