//
//  IdentifierBinaryTree.cpp
//  Lab4
//
//  Created by Bryce Holton on 3/28/14.
//  Copyright (c) 2014 Bryce Holton. All rights reserved.
//	Updated by:
//	Savannah Puckett (snpucket)
//	Ashley Kruger (alkruege)
//	Emily Falkner (emilymarie)
//	Scott Dexhimer (SDexh)
//	Git Hub URL: https://github.com/Thelandofsunshine/Revenge-of-the-Sunshine

#include "IdentifierBinaryTree.h"
#include "LineNumberList.h"
#include "Literal.h"

using namespace std;

IdentifierBinaryTree::IdentifierBinaryTree()
{
    setTreeRoot(NULL);
}
IdentifierBinaryTree::~IdentifierBinaryTree()
{
    Literal *root = getTreeRoot();
    
    if (root != NULL)
    {
        depthFirstDeleteTree(root);
    }
}
void IdentifierBinaryTree::depthFirstDeleteTree(Literal *lit)
{
    if (lit->getLeftChild() != NULL)
    {
        depthFirstDeleteTree(lit->getLeftChild());
    }
//    cout << tok->getTokenString() << "\n";
    if (lit->getRightChild() != NULL)
    {
        depthFirstDeleteTree(lit->getRightChild());
    }
    delete lit;
}
void IdentifierBinaryTree::setTreeRoot(Literal *root)
{
    this->treeRoot = root;
}
Literal *IdentifierBinaryTree::getTreeRoot()
{
    return this->treeRoot;
}
bool IdentifierBinaryTree::addIdentifier(Literal *lit, int lineNum)
{
    bool success = false;
    LineNumberList *listItem = new LineNumberList();
    
    listItem->setLineNumber(lineNum);
    if (getTreeRoot() == NULL)
    {
        setTreeRoot(lit);
        lit->addToLineNumberList(listItem);
        success = true;
    }
    else
    {
        string literalName = lit->getTokenString();
        Literal *parentNode = getTreeRoot();
        string treeNodeName;
        int stringComparison;
        
        while (parentNode != NULL)
        {
            treeNodeName = parentNode->getTokenString();
            stringComparison = literalName.compare(treeNodeName);
            if (stringComparison == 0)
            {
                //They are the same identifier token we just need to add a new line number to the list.
                parentNode->addToLineNumberList(listItem);
                parentNode = NULL; //Exit the loop
                delete lit;         //We won't need tok and it won't be deleted in main.
                success = true;
            }
            else if (stringComparison < 0)
            {
                //Go to the left.
                if (parentNode->getLeftChild() == NULL)
                {
                    //Add tok to the left
                    lit->addToLineNumberList(listItem);
                    parentNode->setLeftChild(lit);
                    parentNode = NULL;
                    success = true;
                }
                else
                {
                    parentNode = parentNode->getLeftChild();
                }
            }
            else
            {
                //Go to the right.
                if (parentNode->getRightChild() == NULL)
                {
                    //Add tok to the right
                    lit->addToLineNumberList(listItem);
                    parentNode->setRightChild(lit);
                    parentNode = NULL;
                    success = true;
                }
                else
                {
                    parentNode = parentNode->getRightChild();
                }
            }
        }
    }
    return success;
}
