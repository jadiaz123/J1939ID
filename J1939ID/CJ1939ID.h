#pragma once
#include "CJ1939ID.h"
#include <string>

#define ERROR_IS_NOT_HEX 1;

using namespace std;
class CJ1939ID
{
private:
	// Private members
	string IDstr;
	// Private methodos
	void IDstr2upercase();
	// void ClassExceptions();
	bool isIDhex();
public:
	// Public Member

	// Public methods
	CJ1939ID(string);
	string getIDstr(void);
	void setIDstr(string);
	int getIDlength(void);
	int hexStr2int(string);
	int getSAint(void);
	string getSAhexstr(void);
	int getPDUspecificint(void);
	string getPDUspecifichexstr(void);
	string getPDUformathexstr(void);
	int getPDUformatint(void);
	int getDP(void);
	int getEDP(void);
	int getPriorityint(void);
	int getPGNint(void);
	string getPGNhexstr(void);
};