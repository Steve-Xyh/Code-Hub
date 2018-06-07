//  建立二叉树的二叉链表存储结构(严6.70)
//  main.cpp
//  NOJ-DS 15 Bi-branch LL Binary Tree
//
//  Created by Steve X on 2018/6/4.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

struct BinTree{
    char c;
    BinTree *lt,*rt;
    BinTree(char c=0):c(c),lt(NULL),rt(NULL){}
}*T;

void creBinTree(BinTree *T)
{
    cin >> T->c;
    if (T->c == '#') return;            //Null node,the last node of a branch
    if (cin.peek() == ')') return;      //The end mark of a branch
    getchar();                          //Absorb invalid signs such as "," and "(" after input valid info
    creBinTree(T -> lt = new BinTree);
    getchar();                          //Absorb invalid signs such as "," and "(" after input valid info
    creBinTree(T -> rt = new BinTree);
    getchar();                          //Absorb invalid signs such as "," and "(" after input valid info
}

void PreOrder(BinTree *T)
{
    if(T==NULL)return;
    cout<< T->c;
    PreOrder(T->lt);
    PreOrder(T->rt);
}

int main()
{
    T=new BinTree;
    creBinTree(T);
    PreOrder(T);
    cout<<endl;
    return 0;
}
