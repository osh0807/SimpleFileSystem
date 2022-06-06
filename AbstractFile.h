#pragma once
//AbstractFile.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
// 
// This file contains enumerations used in this program and declaration of base class AbstractFile.
//

#include <iostream>
#include <vector>
#include "AbstractFileVisitor.h"
using namespace std;

// enumerations for possible outcomes
enum Errors {
	success
	, fail_to_write
	, size_missmatch
	, wrong_char
	, not_supported
	, existing_file
	, ptr_is_nullptr
	, not_open
	, does_not_exist
	, file_open
	, not_existing_filetype
	, wrong_pwd
	, insert_cmd_err
	, quit_cmd
	, fail_to_create
	, fail_to_add
	, fail_to_open
	, fail_to_execute
	, fail_to_execute_macro
	, cannot_append_img
	, unwritable
};

//abstract declaration with pure virtual functions.
class AbstractFile {
public:
	virtual vector<char> read() = 0;
	virtual int write(vector<char> str) = 0;
	virtual int append(vector<char> str) = 0;
	virtual unsigned int getSize() = 0;
	virtual string getName() = 0;
	virtual void accept(AbstractFileVisitor* afv) = 0;
	virtual AbstractFile* clone(string name) = 0;
	virtual void chmod(string s) = 0;
	virtual ~AbstractFile() = default;
	

private:
	
};
