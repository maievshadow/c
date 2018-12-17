#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

PTreeNode
initTreeNode(ElemType data)
{
     PTreeNode root = NULL;

     return root;
}

PTreeNode
insertTreeNode(PTreeNode pt)
{
    char ch;
    ch = getchar();        //头文件<stdio.h>，相当于scanf("%c", &ch)
    if (ch == '#')
        pt = NULL;
    else
    {
        if(!(pt = (PTreeNode)malloc(sizeof(TreeNode))))
            exit(1);
        pt->data = ch;         //生成根节点
        //pt->lNode = NULL;   //构造左子树
        //pt->rNode = NULL;   //构造右子树

        insertTreeNode(pt->lNode);
        insertTreeNode(pt->rNode);
    }

    printf("create success\n");

    return pt;
}