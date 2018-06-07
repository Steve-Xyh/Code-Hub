//  二叉排序树的合并(严9.38) ##special##
//  main.cpp
//  NOJ-DS 26 BST Merge
//
//  Created by Steve X on 2018/6/6.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int a[1000],b[1000],cnta=0,cntb=0;

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

void InOrder(BinTree *T,int a[],int &cnta)
{
    if(T==NULL)return;
    InOrder(T->lt,a,cnta);                  //BST is an ascending sequence when output inorder
    if(T->c != -1)a[cnta++]=T->c;
    InOrder(T->rt,a,cnta);
}

void BSTMerge()
{
    int i=0,j=0;
    while(!(i>=cnta&&j>=cntb)){
        if(i<cnta&&a[i]<b[j])cout<<a[i++]<<" ";
        else if(j<cntb)cout<<b[j++]<<" ";
    }
    cout<<endl;
}

int main()
{
    T1=new BinTree;
    T2=new BinTree;
    creBinTree(T1);
    creBinTree(T2);
    InOrder(T1,a,cnta);
    InOrder(T2,b,cntb);
    BSTMerge();
    return 0;
}
