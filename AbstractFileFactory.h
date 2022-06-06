#pragma once
//AbstractFileFactory.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file declares the base class AbstractFileFactory which is used by SimpleFileFactory
#include "AbstractFile.h"

using namespace std;
// studio 18 - file factory interface declared here

class AbstractFileFactory {
public:
	virtual AbstractFile* createFile(string filename) = 0;
};

