#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <conio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string>
using namespace std;

#define OK 0

class _GRT
{
	public:
	int system(string command_str);
	int chdir(string target_dir);
	int mkdir(string target_dir,bool rec,int mode=0777);
	/// Return busybox command
	string bcmd(string command,int* ret=nullptr);
	string getmac(int* ret=nullptr);
	/// Get Mac State. 1 ON 0 OFF <0 ERR
	int getwifistate();
	string gettmpfile(int* ret=nullptr);
	string getPublicIP(int* ret=nullptr);
	string getIP(int* ret=nullptr);
	string DNSResolve(string Domain,int* ret=nullptr);
	string find(string FileNameToFind,int* ret=nullptr);
	int isexist(string Filename);
	int canread(string Filename);
	int canwrite(string Filename);
	int canexecute(string Filename);
	_GRT();
	~_GRT();

	private:
	int _system_call(const char* command);
	int _chdir_call(const char* dir);
	int _mkdir_call(const char* dir,int mode);
};

_GRT GRT;
_GRT& runtime=GRT;

int _GRT::system(string command_str)
{
	string tcmd=command_str;
	int ret=_system_call(tcmd.c_str());
	return ret;
}
int _GRT::chdir(string dir)
{
	string tdir=dir;
	int ret=_chdir_call(tdir.c_str());
	return ret;
}
int _GRT::mkdir(string dir,bool rec,int mode)
{
	string tdir=dir;
	if(!rec)
	{
		int ret=_mkdir_call(tdir.c_str(),mode);
		return ret;
	}
}

int _GRT::_system_call(const char* command)
{
	int ret=::system(command);
	return ret;
}

int _GRT::_chdir_call(const char* dir)
{
	int ret=::chdir(dir);
	return ret;
}

int _GRT::_mkdir_call(const char* dir,int mode)
{
	int ret=::mkdir(dir,mode);
	return ret;
}

string _GRT::gettmpfile(int* ret)
{

}




int main()
{
	return 0;
}
