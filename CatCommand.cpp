//CatCommand.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//this file defines each function of CatCommand
#include "CatCommand.h"
#include "BasicDisplayVisitor.h"
#include <sstream>

using namespace std;

//constructor CatCommand 
CatCommand::CatCommand(AbstractFileSystem* afs_) : afs(afs_) {}

//inform usage of CatCommand
void CatCommand::displayInfo() {
	cout << "Concatenate can be invoked with the command: cat <filename> [-a]" << endl;
}


int CatCommand::execute(string s) {
	istringstream iss(s); //wrap input and extract two strings: (1) filename and (2) suffix showing append or not 
	string filename;
	string apd;
	iss >> filename >> apd;
	AbstractFile* fileptr = afs->openFile(filename); 
	if (fileptr == nullptr) {	  //if file does not exist, close file
		afs->closeFile(fileptr);
		return fail_to_open;
	}
	else {
		if (apd != "-a") { //if not append
			cout << "input data to append to the file, \":wq\" to save and quit, or \":q\" to quit without saving" << endl;
			string eachln;
			string input;
			while (true) {		//run while loop and wrap each line into input
				getline(cin, eachln);
				input += eachln;
				if (eachln == ":q") {		
					afs->closeFile(fileptr);
					return success;
				}
				if (eachln == ":wq") {		//if ":wq" is prompted, call write() function to write them into a file 
					vector<char> letters;
					letters.insert(letters.end(), input.begin(), input.end() - subtractingwq);
					fileptr->write(letters);
					afs->closeFile(fileptr);
					return success;
				}
				eachln = "";		//update eachln and put another "\n" for next line
				input = input + "\n";
			}
		}
		else {		//not append
			if (filename.substr(filename.find(".") + 1) == "img") { //if the file is image, fail to append
				return cannot_append_img;
			}
			AbstractFileVisitor* bdv = new BasicDisplayVisitor();		//display existing file by calling accept()
			fileptr->accept(bdv);
			cout << endl;
			cout << "input data to append to the file, \":wq\" to save and quit, or \":q\" to quit without saving" << endl;
			string eachln;
			string input;
			while (1) {		//run while loop and wrap each line into input
				getline(cin, eachln);
				input += eachln;
				if (eachln == ":q") {
					afs->closeFile(fileptr);
					return success;
				}
				if (eachln == ":wq") {		//if ":wq" is prompted, call append() function to write them into a file 
					vector<char> letters;
					letters.insert(letters.end(), input.begin(), input.end() - subtractingwq);
					fileptr->append(letters);
					afs->closeFile(fileptr);
					return success;
				}
				eachln = "";		//update eachln and put another "\n" for next line
				input = input + "\n";
			}

		}
	}
	
}