#pragma once
//AbstractFileVisitor.h
//Authors: Soohoon Oh; soohoonoh@wustl.edu
//		   Crystal Shin; crystal.shin@wustl.edu
//		   Amy Kim; amykim@wustl.edu
//This file declares the base class AbstractFileVisitor which is used by BasicDisplayVisitor and MetaDataDisplayVisitor
// declaration of the file visitor interface here

//forward declaration of ImageFile and TextFile
class ImageFile;
class TextFile;

class AbstractFileVisitor {
public:
	virtual void visit_img(ImageFile* mf) = 0;
	virtual void visit_txt(TextFile* tf) = 0;

private:

};