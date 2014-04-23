//
//  Literal.h
//  Lab4

// Created By:
// Savannah Puckett (snpucket)
// Ashley Kruger (alkruege)
// Emily Falkner (emilymarie)
// Scott Dexhimer (SDexh)

#ifndef __Lab4__Token__
#define __Lab4__Token__

#include <iostream>
#include "common.h"
#include "LineNumberList.h"

using namespace std;



/**************
 this is a valid Pascal Literal.  A Literal must have a literal type,
 a literal value, and a Literal code.
 ***************/
class Literal
{
private:
    TokenCode code;
    LiteralType type;

    string tokenString;
    //What variables and methods am I missing to implement a binary tree.
    Literal *leftChild;
    Literal *rightChild;
    LineNumberList *list;
    
public:
    Literal();
    ~Literal();
    void setCode(TokenCode newCode);
    TokenCode getCode();
    void setType(LiteralType newType);
    LiteralType getType();

	virtual void* get_lit() = 0;
	virtual void set_lit(void *) = 0;

    void setTokenString(string s);
    string getTokenString();
    void setLeftChild(Literal *tok);
    Literal *getLeftChild();
    void setRightChild(Literal *tok);
    Literal *getRightChild();
    void addToLineNumberList(LineNumberList *listItem);
    LineNumberList *getLineNumberList();
};

#endif /* defined(__Lab4__Token__) */
