//ImageFile.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains functions for the ImageFile class.

#include "ImageFile.h"
#include <vector>
using namespace std;

ImageFile:: ImageFile(string s) : 
	name(s), contents({}), size('0'){}

unsigned int ImageFile::getSize() {
	return (unsigned int)contents.size();
}

string ImageFile::getName() {
	return name;
}

int ImageFile::write(vector<char> str) {
	size = str.back();
	//size = static_cast<int>(str.size());
	int intsize = (int)size - 48;
	bool error = false;
	if (pow(intsize,2) == str.size()-1) {
		for (unsigned int i = 0; i < str.size() - 1; i++) {
			if (str[i] == 'X' || str[i] == ' ') {
				contents.push_back(str[i]);
			}
			else{
				error = true;
			}
		}
		if (error) {
			contents.clear();
			size = '0';
			return wrong_char;
		}
		return success;
	}
	else {
		size = '0';
		return size_missmatch;
	}
}

int ImageFile::append(vector<char> str) {
	return not_supported;
}

vector<char> ImageFile::read() {
	return contents;
}

int ImageFile::coordToIndex(int x, int y) {
	int intsize = (int)size - 48;
	return y * intsize + x;
}

void ImageFile::accept(AbstractFileVisitor* afv) {
	afv->visit_img(this);
}

AbstractFile* ImageFile::clone(string name) {
	AbstractFile* copyFile = new ImageFile(name);
	copyFile->write(this->read());
	return copyFile;
}

void ImageFile::chmod(string s) {
	if (s == "-") {
		writable = false;
	}
	else if (s == "+") {
		writable = true;
	}
}