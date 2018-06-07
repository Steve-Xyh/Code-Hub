//  输出以二叉树表示的算术表达式(严6.51)
//  main.cpp
//  NOJ-DS 17 Bi-Tree Calculate
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

void InOrder(BinTree *T)
{
    if(T==NULL)return;
    InOrder(T->lt);
    if(T->c!='#')cout<<T->c;            //Output father between lt and rt
    InOrder(T->rt);
}

int main()
{
    T=new BinTree;
    creBinTree(T);
    InOrder(T);
    cout<<endl;
    return 0;
}
