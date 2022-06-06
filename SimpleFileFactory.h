// SimpleFileFactory.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the SimpleFileFactory class that creates files.

#pragma once
#include "AbstractFileFactory.h"
#include "ImageFile.h"
#include "TextFile.h"


// Studio 18 - simplefilefactory class declaration goes here

class SimpleFileFactory : public AbstractFileFactory {
public:
	AbstractFile* createFile(string filename);
};
