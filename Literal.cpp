//
//  Literal.cpp
//  Lab4
//
//  Created by Bryce Holton.
//	Updated by:
//	Savannah Puckett (snpucket)
//	Ashley Kruger (alkruege)
//	Emily Falkner (emilymarie)
//	Scott Dexhimer (SDexh)
//	Git Hub URL: https://github.com/Thelandofsunshine/Revenge-of-the-Sunshine

#include "Literal.h"

Literal::Literal()
{
    //What code do I need here to initialize everything.
    setLeftChild(NULL);
    setRightChild(NULL);
    list = NULL;
}
Literal::~Literal()
{
    //What code do I need here to free memory
    LineNumberList *root = getLineNumberList();
    LineNumberList *tmp = root;
    
    while (root != NULL)
    {
        tmp = tmp->getNextLineNumber();
        delete root;
        root = tmp;
    }
    if (this->getType() == STRING_LIT)
    {
        //free(this->literal.stringLiteral);
    }
}
void Literal::setCode(TokenCode newCode)
{
    this->code = newCode;
}
TokenCode Literal::getCode()
{
    return this->code;
}
void Literal::setType(LiteralType newType)
{
    this->type = newType;
}
LiteralType Literal::getType()
{
    return this->type;
}
void Literal::setTokenString(string s)
{
    this->tokenString = s;
}
string Literal::getTokenString()
{
    return this->tokenString;
}
//What methods am I missing to implement a binary tree.
void Literal::setLeftChild(Literal *tok)
{
    this->leftChild = tok;
}
Literal *Literal::getLeftChild()
{
    return this->leftChild;
}
void Literal::setRightChild(Literal *tok)
{
    this->rightChild = tok;
}
Literal *Literal::getRightChild()
{
    return this->rightChild;
}
void Literal::addToLineNumberList(LineNumberList *listItem)
{
    LineNumberList *tmp = getLineNumberList();
    
    if (tmp == NULL)
    {
        list = listItem;
    }
    else
    {
        while (tmp->getNextLineNumber() != NULL)
        {
            tmp = tmp->getNextLineNumber();
        }
        tmp->setNextLineNumber(listItem);
    }
}
LineNumberList *Literal::getLineNumberList()
{
    return this->list;
}
