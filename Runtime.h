#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <conio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include <string>
#include <stdexcept>
using namespace std;

#define OK 0

class GRT
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
	int canrw(string Filename);
	int isfile(string Address);
	int isdir(string Address);
	GRT();
	~GRT();

	private:
	int _system_call(const char* command);
	int _chdir_call(const char* dir);
	int _mkdir_call(const char* dir,int mode);

	int _isexist(const char* filename);
	int _canread(const char* filename);
	int _canwrite(const char* filename);
	int _canexecute(const char* filename);
	int _canrw(const char* filename);
	int _isfile(const char* addr);
	int _isdir(const char* addr);

	/// Static Counter
	static int __counter;
};
int GRT::__counter=0;
