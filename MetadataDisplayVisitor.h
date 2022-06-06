// MetadataDisplayVisitor.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file contains declarations for the MetadataDisplayVisitor class which displays information about the images or text files visited.

#pragma once
#include "AbstractFileVisitor.h"
// declaration of MetadataDisplayVisitor here

class MetadataDisplayVisitor : public AbstractFileVisitor {
public:

	void visit_img(ImageFile* mf);
	void visit_txt(TextFile* tf);
};