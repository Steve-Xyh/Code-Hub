//  二叉排序树的判别(耿8.6)
//  main.cpp
//  NOJ-DS 24 Judge Bi-Sorting Tree
//
//  Created by Steve X on 2018/6/6.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int tmp=0;
bool ans=true;

struct BinTree{
    int c;
    BinTree *lt,*rt;
    BinTree(int c=0):c(c),lt(NULL),rt(NULL){}
}*T;

void creBinTree(BinTree *T)
{
    cin >> T->c;
    if (T->c ==-1) return;              //Null node,the last node of a branch
    creBinTree(T->lt=new BinTree);
    creBinTree(T->rt=new BinTree);
}

void InOrder(BinTree *T)
{
    if(T==NULL)return;
    InOrder(T->lt);                     //BST is an ascending sequence when output inorder
    if(T->c > 0 && T->c < tmp){
        ans=false;
        return;
    }
    tmp=T->c;
    InOrder(T->rt);
}

int main()
{
    T=new BinTree;
    creBinTree(T);
    InOrder(T);
    if(ans)cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}
