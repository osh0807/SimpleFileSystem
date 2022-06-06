//BasicDisplayVisitor.cpp
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//this file defines each function of BasicDisplayVisitor

#include "BasicDisplayVisitor.h"
#include "ImageFile.h"
#include "TextFile.h"
using namespace std;

//visit ImageFiles, call read() to get vector of ImageFile and print out elements.
void BasicDisplayVisitor::visit_img(ImageFile* mf) {
	int intsize = mf->getSize();
	int size = (int)sqrt(intsize);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			int index = mf -> coordToIndex(j, i);
			cout << mf->read()[index];
		}
	cout << endl;
	}
}

//visit TextFiles, call read() to get vector of TextFile and print out elements.
void BasicDisplayVisitor::visit_txt(TextFile* tf) {
	for (char a : tf->read()){
		cout << a;
	}
	cout << endl;
}

