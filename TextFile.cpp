// TextFile.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains functions for the Textfile class.

#include "TextFile.h"
#include <iostream>
#include <vector>

using namespace std;

TextFile::TextFile(string name):
	name_(name) {}

unsigned int TextFile :: getSize() {
	return (unsigned int) contents.size();
}

string TextFile :: getName() {
	return name_;
}

int TextFile :: write(vector<char> str) {
	if (writable == true) {
		contents = str;
		if (contents == str) {
			return success;
		}
		return fail_to_write;
	}
	else {
		return unwritable;
	}
	
}

int TextFile :: append(vector<char> newS) {
	if (writable == true) {
		for (char a : newS) {
			contents.push_back(a);
		}
		return success;
	}
	else {
		return unwritable;
	}
}

vector<char> TextFile::read() {
	return contents;
}

void TextFile::accept(AbstractFileVisitor* afv) {
	afv->visit_txt(this);
}

AbstractFile* TextFile::clone(string name) {
	AbstractFile* copyFile = new TextFile(name);
	copyFile->write(this->read());
	return copyFile;
}

void TextFile::chmod(string s) {
	if (s == "-") {
		writable = false;
	}
	else if (s == "+") {
		writable = true;
	}	
}