#include "Runtime.h"
using namespace std;

GRT::GRT()
{
    if(GRT::__counter)
    {
        throw runtime_error("Cannot Create Another Runtime Object.\n");
    }
    GRT::__counter=1;
}

GRT::~GRT()
{
    GRT::__counter=0;
}

int GRT::system(string command_str)
{
	string tcmd=command_str;
	int ret=_system_call(tcmd.c_str());
	return ret;
}
int GRT::chdir(string dir)
{
	string tdir=dir;
	int ret=_chdir_call(tdir.c_str());
	return ret;
}
int GRT::mkdir(string dir,bool rec,int mode)
{
	string tdir=dir;
	if(rec==false)
	{
		int ret=_mkdir_call(tdir.c_str(),mode);
		return ret;
	}
    size_t done=1;
    while(1)
    {
        if(done>=tdir.size()) break;
        string::size_type ret=tdir.find("/",done);
        if(ret==string::npos)
        {
            ret=tdir.size();
        }
        string cdir=tdir.substr(0,ret);
        _mkdir_call(cdir.c_str(),mode);
        done=ret+1;
    }
    if(isexist(dir))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int GRT::_system_call(const char* command)
{
	int ret=::system(command);
	return ret;
}

int GRT::_chdir_call(const char* dir)
{
	int ret=::chdir(dir);
	return ret;
}

int GRT::_mkdir_call(const char* dir,int mode)
{
    #ifndef __C4DROID__
    int ret=::mkdir(dir);
    #else
	int ret=::mkdir(dir,mode);
	#endif // __C4DROID__
	return ret;
}

int GRT::isexist(string Filename)
{
    string tFilename=Filename;
    return _isexist(tFilename.c_str());
}

int GRT::canread(string Filename)
{
    string tFilename=Filename;
    return _canread(tFilename.c_str());
}

int GRT::canwrite(string Filename)
{
    string tFilename=Filename;
    return _canwrite(tFilename.c_str());
}

int GRT::canexecute(string Filename)
{
    string tFilename=Filename;
    return _canexecute(tFilename.c_str());
}

int GRT::canrw(string Filename)
{
    string tFilename=Filename;
    return _canrw(tFilename.c_str());
}


int GRT::_isexist(const char* filename)
{
	return (access(filename,F_OK)==0);
}
int GRT::_canexecute(const char* filename)
{
	return (access(filename,X_OK)==0);
}
int GRT::_canwrite(const char* filename)
{
	return (access(filename,W_OK)==0);
}
int GRT::_canread(const char* filename)
{
	return (access(filename,R_OK)==0);
}
int GRT::_canrw(const char* filename)
{
	return ((access(filename,R_OK)==0)&&(access(filename,W_OK)==0));
}

string GRT::gettmpfile(int* ret)
{

}


GRT runtime;

int main()
{
	return 0;
}
