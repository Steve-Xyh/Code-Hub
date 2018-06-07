//  计算二叉树叶子结点数目(耿6.14)
//  main.cpp
//  NOJ-DS 16 Cnt Bi-Tree Leaf Node
//
//  Created by Steve X on 2018/6/6.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int ans=0;

struct BinTree{
    char c;
    BinTree *lt,*rt;
    BinTree(char c=0):c(c),lt(NULL),rt(NULL){}
}*T;

void creBinTree(BinTree *T)
{
    cin >> T->c;
    if (T->c == '#') return;            //Null node,the last node of a branch
    creBinTree(T -> lt = new BinTree);
    creBinTree(T -> rt = new BinTree);
}

void PreOrder(BinTree *T)
{
    if(T==NULL)return;                  //Leaf nodes have 2 children with "#"
    if(T->lt&&T->lt->c=='#'&&T->rt->c=='#')ans++;
    PreOrder(T->lt);
    PreOrder(T->rt);
}

int main()
{
    T=new BinTree;
    creBinTree(T);
    PreOrder(T);
    cout<<ans<<endl;
    return 0;
}
