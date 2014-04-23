//
//  Print.h
//  Lab4
//
//  Created by Bryce Holton.
//	Updated by:
//	Savannah Puckett (snpucket)
//	Ashley Kruger (alkruege)
//	Emily Falkner (emilymarie)
//	Scott Dexhimer (SDexh)
//	Git Hub URL: https://github.com/Thelandofsunshine/Revenge-of-the-Sunshine

#ifndef __Lab4__Print__
#define __Lab4__Print__

#include <iostream>
#include "common.h"
#include "Literal.h"

using namespace std;

class Print
{
private:
    string sourceFileName;
    string currentDate;
    int pageNumber;
    int lineCount;
    
    void printPageHeader();
    
public:
    Print(char source_name[], char date[]);
    ~Print();
    
    void printLine(char line[], bool token);
    void printLit(Literal *token);
    int getLineCount();
    void printTree(Literal *identifier);
    void printTreeRecursive(Literal *identifier);
};

#endif /* defined(__Lab4__Print__) */
