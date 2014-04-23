//
//  Literal.h
//  Lab4
//
// Savannah Puckett (snpucket)
// Ashley Kruger (alkruege)
// Emily Falkner (emilymarie)
// Scott Dexhimer (SDexh)

#ifndef Lit_h
#define Lit_h

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

	virtual void print() = 0;

    void setTokenString(string s);
    string getTokenString();
    void setLeftChild(Literal *tok);
    Literal *getLeftChild();
    void setRightChild(Literal *tok);
    Literal *getRightChild();
    void addToLineNumberList(LineNumberList *listItem);
    LineNumberList *getLineNumberList();
};

template<class T>
class Node: public Literal
{
private:
	T lit;
public:
	Node(T liter)				{lit = liter;}
	T get_lit()					{return lit;}
	void set_lit(T liter)		{lit = liter;}
	virtual void print() = 0;
};

class String : public Node<string>
{
public:
	String (string str) : Node<string> (str) {}
	void print();
};
class Real : public Node<float>
{
public:
	Real (float dbl) : Node<float> (dbl) {}
	void print();
};
class Integer : public Node<int>
{
public:
	Integer (int i) : Node<int> (i) {}
	void print();
};

#endif 