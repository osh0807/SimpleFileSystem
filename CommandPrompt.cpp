//CommandPrompt.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//this file defines each function of ComandPrompt
#include "CommandPrompt.h"
#include "AbstractFile.h"
#include <string>
#include <sstream>

using namespace std;


CommandPrompt::CommandPrompt() {
	aff = nullptr;
	afs = nullptr;
}

void CommandPrompt::setFileSystem(AbstractFileSystem* filesys) {
	afs = filesys;
}

void CommandPrompt::setFileFactory(AbstractFileFactory* filefact) {
	aff = filefact;
}

int CommandPrompt::addCommand(string name, AbstractCommand* ac) {
	if (sToAc.insert(pair<string, AbstractCommand*>(name, ac)).second) {		//insert command with its name into map
		return success;
	}
	else {
		return insert_cmd_err;
	}
}

void CommandPrompt::listCommands() {
	map<string, AbstractCommand*>::iterator it;
	for (it = sToAc.begin(); it != sToAc.end(); it++) {		//iterates map and show each command name
		cout << it->first << " ";
	}
	cout << endl;
}

string CommandPrompt::prompt() {		//prompt user to type in a command
	string command;
	cout << "type either a valid command, 'q' to quit, 'help' for a list of commands or 'help <command name>' for details about a specific command" ;
	cout << endl << "$" << "   ";
	getline(cin, command);
	return command;
}

int CommandPrompt::run() {		//run command program
	while (1) {
		string cmd = prompt();
		if (cmd == "q") {
			return quit_cmd;
		}
		else if (cmd.compare("help") == success) {
			listCommands();
		}
		// if there is one word
		else if (cmd.find(' ') == string::npos) {
			auto it = sToAc.find(cmd);
			if (it != sToAc.end()) {
				int s = it->second->execute("");		//execute() the command

				if (s != success) {						//execute() result is not success
	
					cout << "Failed to execute" << endl;
				}
			}
			else {											// not in the command list
				cout << "Command does not exist" << endl;
			}
		}
		else {					 // more than one words
			string first_word;
			istringstream iss;
			iss.str(cmd);
			iss >> first_word;
			

			if (first_word == "help") {				//starts with "help"
				string second_word;
				iss >> second_word;
				auto it = sToAc.find(second_word);
				if (it!= sToAc.end()) {
					it->second->displayInfo();		//call displayInfo() for it
				}
				else {
					cout << "Command Does Not Exist.";
				}
			}
			else {
				auto it = sToAc.find(first_word);
				if (it != sToAc.end()) {							//execute() the command with following arguments as parameter
					string sRemain = cmd.substr(cmd.find(' ') + 1);
					int result = it->second->execute(sRemain);
					if (result != success) {
						cout << "error no: " << result << endl;
						cout << "command failed"<< endl;
					}
				}
				else {
					cout << "Unable to find command";
				}
			}

		}
	}
}

