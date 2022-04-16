#include "CJ1939ID.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string CJ1939ID::getIDstr()
{
	return IDstr;
}

void CJ1939ID::setIDstr(string _IDstr)
{
	IDstr = _IDstr;
	IDstr2upercase();
	// ClassExceptions();
}

CJ1939ID::CJ1939ID(string _IDstr)
{
	IDstr = _IDstr;
	IDstr2upercase();
	// ClassExceptions();
}

int CJ1939ID::getIDlength()
{
	return IDstr.size();
}

void CJ1939ID::IDstr2upercase()
{
	int IDlength = getIDlength();

	for (int i= 0; i <= IDlength; i++)
	{
		if (IDstr[i] >= 97 && IDstr[i] <= 122)
		{
			IDstr[i] -= 32;
		}
	}
}

bool CJ1939ID::isIDhex()
{
	int IDlength = getIDlength();
	bool b_isIDhex = true;
	for (int i = 0; i < IDlength; i++)
	{
		if (IDstr[i] <= 47 || (IDstr[i] >= 58 && IDstr[i] <= 64) || IDstr[i] >= 71)
		{
			b_isIDhex = false;
		}
	}
	return b_isIDhex;
}

int CJ1939ID::getSAint(void)
{
	int x;
	stringstream ss;
	ss << hex << IDstr.substr(6,2);
	ss >> x;
	return x;
}

string CJ1939ID::getSAhexstr(void)
{
	return IDstr.substr(6, 2);
}

int CJ1939ID::getPDUspecificint(void)
{
	int x;
	stringstream ss;
	string sss = IDstr.substr(4, 2);
	ss << hex << sss ;
	ss >> x;
	return x;
}

string CJ1939ID::getPDUspecifichexstr(void)
{
	return IDstr.substr(4, 2);
}

int CJ1939ID::getPDUformatint(void)
{
	int x;
	stringstream ss;
	string sss = IDstr.substr(2, 2);
	ss << hex << sss;
	ss >> x;
	return x;
}

string CJ1939ID::getPDUformathexstr(void)
{
	return IDstr.substr(2, 2);
}

int CJ1939ID::getDP(void)
{
	int x;
	stringstream ss;
	
	ss << hex << IDstr.substr(1, 1);
	ss >> x;
	return (x & 0b0001);
}

int CJ1939ID::getEDP(void)
{
	int x;
	stringstream ss;

	ss << hex << IDstr.substr(1, 1);
	ss >> x;
	return (x & 0b0010)>>1;
}

int CJ1939ID::getPriorityint(void)
{
	int x;
	stringstream ss;

	ss << hex << IDstr.substr(0, 2);
	ss >> x;
	return (x & 0b00011100) >> 2;
}

int CJ1939ID::getPGNint(void)
{
	if (getPDUformatint() < 240)
	{
		return getPDUformatint() << 8;
	}
	else
	{
		return (getPDUformatint() << 8) + getPDUspecificint();
	}
}

string CJ1939ID::getPGNhexstr(void)
{
	if (getPDUformatint() < 240)
	{
		return getPDUformathexstr() + "00";
	}
	else
	{
		return getPDUformathexstr()+getPDUspecifichexstr();
	}
}



//int CJ1939ID::hexStr2int(string val)
//{
//	return toInt64(val);
//}

//void CJ1939ID::ClassExceptions()
//{
//	try
//	{
//		if (!isIDhex())
//		{
//			throw ERROR_IS_NOT_HEX;
//		}
//	}
//	catch (int e)
//	{
//		switch (e)
//		{
//		case 1:
//			cout << "ID is not a hexadecimal number" << endl;
//			break;
//		default:
//			break;
//		}
//	}
//}

