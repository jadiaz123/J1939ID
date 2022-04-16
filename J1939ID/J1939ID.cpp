// J1939ID.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CJ1939ID.h"
#include <string>
#include <sstream>
using namespace std;

int main()
{

    string idstr = "1410F131";
    CJ1939ID id(idstr);


    cout << id.getIDlength() << endl;
    cout << id.getIDstr() << endl;

    cout << id.getPDUspecificint() << endl;
    cout << id.getPDUspecifichexstr() << endl;

    cout << id.getSAint() << endl;
    cout << id.getSAhexstr() << endl;

    cout << id.getPDUformatint() << endl;
    cout << id.getPDUformathexstr() << endl;

    cout << id.getDP() << endl;
    cout << id.getEDP() << endl;

    cout << id.getPriorityint() << endl;

    cout << id.getPGNint() << endl;
    cout << id.getPGNhexstr() << endl;


    cout << "ID: " <<id.getIDstr() << endl;
    cout << "PGN: " << id.getPGNint() << endl;
    cout << "DP: " << id.getDP() << endl;
    cout << "EDP: " << id.getDP() << endl;
    cout << "Priority: " << id.getPriorityint() << endl;
    cout << "        1 |    4    |     F   |    E    |    F    |    1    |    3    |    1     | " << endl;
    cout << "        1 | 1 0 0 1 | 0 0 0 0 | 0 0 0 1 | 1 0 0 1 | 1 0 0 1 | 1 0 0 1 | 1 0 0 1  | " << endl;
  
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
