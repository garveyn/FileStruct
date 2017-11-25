//
//  FileStructure.cpp
//  FileSystems
//
//  Created by Anderson, Sloan on 11/17/17.
//  Copyright © 2017 Anderson, Sloan. All rights reserved.
//

#include "FileStructure.h"


FileStructure::Folder::Folder(bool dir)
{
	this->childrenArr.resize(2);

	isDir = dir;
	childrenArr[DOT] = this;
}

FileStructure::Folder::Folder(string newName, Folder *newParent, bool dir)
{
	this->childrenArr.resize(2);

	name = newName;
	childrenArr[DOT] = this;
	childrenArr[DOT_DOT] = newParent;
	isDir = dir;

}

void FileStructure::addNode(string name, bool isDir)
{
	{
		if (isDir) {
			Folder *newFolder = new Folder(name, mCurrentFolder, true);
			mCurrentFolder->childrenArr.push_back(newFolder);
		}
		else {
			Folder *newFile = new Folder(false);
			newFile->name = name;

			mCurrentFolder->childrenArr.push_back(newFile);  // not to sure about this syntax
		}
	}
}

FileStructure::FileStructure()
{
	mRoot = new Folder(true);
	mRoot->childrenArr[DOT_DOT] = mRoot;
	mRoot->name = "ROOT";
	mCurrentFolder = mRoot;
}

void FileStructure::mkdir(string dirName)
{
	addNode(dirName, true);
}

void FileStructure::mkfile(string fileName)
{
	addNode(fileName, false);
}

void FileStructure::cd(string dir)
{
	if (dir == "..")
	{
		mCurrentFolder = mCurrentFolder->childrenArr[DOT_DOT];
		return;
	}
	else if (dir == ".") {
		return;
	}
	else {
		for (auto i : mCurrentFolder->childrenArr)
		{
			if (i->name == dir && i->isDir)
			{
				mCurrentFolder = i;
				return;
			}
			else if (!i->isDir)
			{
				cout << "Error: " << dir << " is not a directory" << endl;
				return;
			}
		}
		cout << "Error: Directory Does Not Exist" << endl;
	}
}

void FileStructure::pwd()
{
	cout << "Your current directory is : " << mCurrentFolder->name << endl;
}

void FileStructure::ls()
{
	cout << "." << endl
		 << ".." << endl;
	for (auto i : mCurrentFolder->childrenArr)
	{
		if (i->name != mCurrentFolder->childrenArr[DOT]->name &&
			i->name != mCurrentFolder->childrenArr[DOT_DOT]->name)
				cout << i->name << endl;
	}
}

void FileStructure::rmfile(string fileName)
{
	int b = 0;
		for (auto i : mCurrentFolder->childrenArr)
		{
			if (i->name == fileName && i->isDir == false)
			{
				mCurrentFolder->childrenArr.erase(mCurrentFolder->childrenArr.begin() + b);
				return;
			}
			b++;
		}
	cout << "ERROR" << endl;
}

void FileStructure::rmdir(string folderName)
{
	int i = 0;

	if (mCurrentFolder->name == folderName || mCurrentFolder->childrenArr[0]->name == folderName)
	{
		cout << "Can not remove current directory" << endl;
		return;
	}

	for (auto b : mCurrentFolder->childrenArr)
	{
		if (b->name == folderName && b->isDir == true)
		{
			if (mCurrentFolder->childrenArr[i]->childrenArr.size() == 2)
			{
				mCurrentFolder->childrenArr.erase(mCurrentFolder->childrenArr.begin() + i);
				return;
			}
			else
			{
				cout << "Folder is not empty" << endl;
				return;
			}
		}
		i++;
	}
}