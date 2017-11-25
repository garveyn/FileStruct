#include "header.h"


int main() 
{
	string unValInput, funct, arg;
	int split;
	FileStructure fs;

	while (true)
	{
		
		getline(cin, unValInput);

		if (unValInput == "exit")
			break;

		split = unValInput.find_first_of(" ");
		if (split == string::npos && unValInput != "ls" && unValInput != "pwd")
		{
			cout << "Invalid input: You need to give arguments for the function you are trying to access" << endl;
			continue;
		}

		funct = unValInput.substr(0, split);
		arg = unValInput.substr(split + 1);

		if (funct == "mkdir")
			fs.mkdir(arg);
		else if (funct == "rmdir")
			fs.rmdir(arg);
		else if (funct == "mkfile")
			fs.mkfile(arg);
		else if (funct == "rmfile")
			fs.rmfile(arg);
		else if (funct == "cd")
			fs.cd(arg);
		else if (funct == "ls")
			fs.ls();
		else if (funct == "pwd")
			fs.pwd();
		else
			cout << "No such function : " << funct << endl;

	}




    return 0;
}
