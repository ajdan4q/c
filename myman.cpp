/*
* Filename: myman.cpp
* Description: myman, a wrap of GNU man, ro avoid messcode when showing
*              manuals in vim througn C.vim plugin.
* Update:
* Date         Name            Reason
* ========== =================
** 05/14/09 YangYingchao, Create
** 05/15/09 YangYingchao, Updare a return value.
** 05/20/09 YangYingchao, Update default sections when searching manuals.
**/

#include        <iostream>
#include        <string>
#include        <errno.h>
#include        <stdlib.h>
#include        <unistd.h>
#include        <sstream>
using namespace std;


bool isFileExist(string Path)
{
	if(access(Path.c_str(), F_OK))
		return false;
	else
		return true;
}

int main ( int argc, char *argv[] )
{
	if (argc != 2) {
		cout << "Usage: " << argv[0] << " Func_Name" << endl;
		exit(0);
	}

	string Man = "man ";
	string Suffix= " | col -b | less";
	string Func = "";
	string path = "/usr/share/man/man";
	string Path;
	string tmp;
	int i = 0, j = 0;

	string Row[] = {"3", "2", "1", "0", "4", "5", "6", "7", "8", "9"};
	string Col[] = {"", "x", "l", "p"};

	int M = sizeof(Row)/sizeof(string);
	int N = sizeof(Col)/sizeof(string);

	Func = argv[1];


	for (i = 0; i < M ; i++) {
		for (j = 0; j < N; j++) {
		Path = "";
		tmp = Row[i] + Col[j];
		Path = path + tmp + "/" + Func + "." + tmp + ".gz";
		if (!isFileExist(Path)) {
			if(i < M-1) {
				continue;
			}
			else {
				return -1;
			}
		}
		else {
			Man = Man + " " +tmp + " " + Func + Suffix;
			system(Man.c_str());
			return 0;
		}
		}
	}
	return 0;
}
