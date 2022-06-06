// PasswordProxy.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the PasswordProxy class that password protects a file.

#pragma once
#include "AbstractFile.h"
class PasswordProxy : public AbstractFile {
public:
	PasswordProxy(AbstractFile* file, string pwrd);
	~PasswordProxy();
	vector<char> read();
	int write(vector<char> str);
	int append(vector<char> str);
	unsigned int getSize();
	string getName();
	void accept(AbstractFileVisitor* afv);
	AbstractFile* clone(string name);
	void chmod(string s);
protected:
	string passwordPrompt();
private:
	AbstractFile* fileptr;
	string pwd;
};
