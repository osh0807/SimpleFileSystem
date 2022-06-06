#pragma once
//BasicDisplayVisitor.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file declares BasicDisplayVisitor which publicly inherits AbstractFileVisitor

#include "AbstractFileVisitor.h"

class BasicDisplayVisitor: public AbstractFileVisitor {
public:
	void visit_img(ImageFile* mf);
	void visit_txt(TextFile* tf);
private:

};
