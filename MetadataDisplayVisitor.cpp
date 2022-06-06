// MetadataDisplayVisitor.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains functions for the MetadataDisplayVisitor class.

#include "MetadataDisplayVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"
using namespace std;

void MetadataDisplayVisitor::visit_img(ImageFile* mf) {
	cout << mf->getName();
	size_t numSpaces = 20 - mf->getName().length();
	string spaces = std::string(numSpaces, ' ');
	cout << spaces << "image";
	string anotherSpaces = std::string(5, ' ');
	cout << spaces << mf->getSize();
	
}

void MetadataDisplayVisitor::visit_txt(TextFile* tf) {
	cout << tf->getName();
	size_t numSpaces = 20 - tf->getName().length();
	string spaces = std::string(numSpaces, ' ');
	cout << spaces << "text";
	string anotherSpaces = std::string(6, ' ');
	cout << anotherSpaces << tf->getSize();
	
}

