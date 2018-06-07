//  二叉排序树的插入和删除(严9.35、9.36和9.37)    ##special##
//  main.cpp
//  NOJ-DS 25 BST Insert and Delete
//
//  Created by Steve X on 2018/6/6.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
using namespace std;

int a[1000],cnt=0;

struct BinTree{
    int c;
    BinTree *lt,*rt;
    BinTree(int c=0):c(c),lt(NULL),rt(NULL){}
}*T;

void creBinTree(BinTree *T)
{
    cin >> T->c;
    if (T->c == -1) return;             //Null node,the last node of a branch
    creBinTree(T->lt=new BinTree);
    creBinTree(T->rt=new BinTree);
}

void InOrder(BinTree *T)
{
    if(T==NULL)return;
    InOrder(T->lt);                     //BST is an ascending sequence when output inorder
    if(T->c != -1)a[cnt++]=T->c;
    InOrder(T->rt);
}

void solve()
{
    int l,r,ins,del;
    bool tag=true;
    InOrder(T);
    cin>>l>>r>>ins>>del;
    for(int i=0;i<cnt;i++)if(l<a[i]&&a[i]<r)cout<<a[i]<<" ";
    cout<<endl;
    for(int i=0;i<cnt;i++){
        if(tag&&ins<=a[i]){
            cout<<ins<<" ";
            tag=false;
        }
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<cnt;i++)if(a[i]!=del)cout<<a[i]<<" ";
    cout<<endl;
}

int main()
{
    T=new BinTree;
    creBinTree(T);
    solve();
    return 0;
}
