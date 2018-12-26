#ifndef __TREE__H
#define __TREE__H

typedef int ElemType;

// ------------- //
// tree node def; //
// ------------- //
typedef struct TreeNode{
    
    ElemType data; // 
    
    struct TreeNode * lNode; //

    struct TreeNode * rNode; // 

}TreeNode, * PTreeNode;

// ---------------------------- //
//  visit node and do something; //
// ---------------------------- //
typedef void (*visit)(void *, void *);

// ----------------- //
// init tree node; //
// ----------------- //
PTreeNode
initTreeNode(ElemType); 

// ----------------- //
// create tree node; //
// ----------------- //
PTreeNode
insertTreeNode(PTreeNode); 

// ----------------------------------- //
// pre order tree node and visit node; //
// ----------------------------------- //
int
preOrderTreeNode(PTreeNode, visit);

// ---------------------------------- //
// In order tree node and visit node; //
// ---------------------------------- //
int
InOrderTreeNode(PTreeNode, visit);

// ------------------------------------ //
// post order tree node and visit node; //
// ------------------------------------ //
int
postOrderTreeNode(PTreeNode, visit);

#endif