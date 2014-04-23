//
//  IdentifierBinaryTree.h
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
#ifndef __Lab4__IdentifierBinaryTree__
#define __Lab4__IdentifierBinaryTree__

#include <iostream>
#include "Token.h"
#include "Literal.h"

class IdentifierBinaryTree
{
    Literal  *treeRoot;
    
    void depthFirstDeleteTree(Literal *lit);
    
public:
    IdentifierBinaryTree();
    ~IdentifierBinaryTree();
    void setTreeRoot(Literal *root);
    Literal *getTreeRoot();
    bool addIdentifier(Literal *lit, int lineNum);
};

#endif /* defined(__Lab4__IdentifierBinaryTree__) */
