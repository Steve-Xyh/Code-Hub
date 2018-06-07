//  建立二叉树的二叉链表(严6.65)   ##DNF##
//  main.cpp
//  NOJ-DS 18 BT Pre&InOrder to PostOrder
//
//  Created by Steve X on 2018/6/7.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
using namespace std;

struct BinTree{
    int c;
    BinTree *lt,*rt;
    BinTree(int c=0):c(c),lt(NULL),rt(NULL){}
}*T1,*T2;

void creBinTree(BinTree *T)
{
    cin >> T->c;
    if (T->c == -1) return;                 //Null node,the last node of a branch
    creBinTree(T->lt=new BinTree);
    creBinTree(T->rt=new BinTree);
}



void PostOrder(BinTree *T)
{
    if(T==NULL)return;
    PostOrder(T->lt);
    PostOrder(T->rt);
    cout<<T->c<<" ";
}

int main()
{
    
    
    return 0;
}
