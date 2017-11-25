//
//  FileStructure.h
//  FileSystems
//
//  Created by Anderson, Sloan on 11/17/17.
//  Copyright © 2017 Anderson, Sloan. All rights reserved.
//

#ifndef FileStructure_h
#define FileStructure_h

#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int DOT = 1;
const int DOT_DOT = 0;



class FileStructure{
    
    struct Folder
    {
        string name;
        vector<Folder*> childrenArr;
        bool isDir;
        Folder(bool dir = true);
		Folder(string newName, Folder *newParent, bool dir);
    };

    
    Folder *mRoot;
    Folder *mCurrentFolder;
    
    
	void addNode(string name, bool isDir);

public:
    FileStructure();
    
	void mkdir(string dirName);
	void mkfile(string fileName);
    
	void cd(string dir);
	void pwd();
	void ls();

	void rmfile(string filename);
	void rmdir(string foldername);
};


#endif /* FileStructure_h */
