// PasswordProxy.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains functions for the PasswordProxy class.

#include "PasswordProxy.h"
#include <iostream>
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* file, string pwrd) {
	fileptr = file;
	pwd = pwrd;
}

PasswordProxy::~PasswordProxy() {
	delete fileptr;
}

string PasswordProxy::passwordPrompt() {
	string password;
	cout << "type your password" << endl;
	cin >> password;
	cin.ignore();
	return password;
}

vector<char> PasswordProxy::read() {
	string prompt = passwordPrompt();
	if (prompt == pwd) {
		return fileptr->read();
	}
	vector<char> empty;
	return empty;
}

int PasswordProxy::write(vector<char> str) {
	string prompt = passwordPrompt();
	if (prompt == pwd) {
		return fileptr->write(str);
	}
	return wrong_pwd;
}

int PasswordProxy::append(vector<char> str) {
	string prompt = passwordPrompt();
	if (prompt == pwd) {
		return fileptr->append(str);
	}
	return wrong_pwd;
}

unsigned int PasswordProxy::getSize() {
	return fileptr->getSize();
}

string PasswordProxy::getName() {
	return fileptr->getName();
}

void PasswordProxy::accept(AbstractFileVisitor* afv) {
	string prompt = passwordPrompt();
	if (prompt.compare(pwd) == 0) {
		fileptr->accept(afv);
	}
}

AbstractFile* PasswordProxy::clone(string name) {
	AbstractFile* copyFile = fileptr->clone(name);
	AbstractFile* cloneProxy = new PasswordProxy(copyFile, pwd);
	return cloneProxy;
}

void PasswordProxy::chmod(string s) {}