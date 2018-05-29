//  单链表的删除(严2.29)
//  main.cpp
//  NOJ-DS 5 delete node
//
//  Created by Steve X on 2018/3/20.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdlib>
using namespace std;

typedef int DataType;           //定义元素类型为整型
typedef struct Node{            //单链表结点结构
    DataType info;
    struct Node *next;
}*PNode;                        //结点指针类型

typedef struct LinkList{        //单链表类型定义
    PNode head;                 //指向单链表中的第一个结点
}*PLinkList;                    //单链表类型的指针类型

void InsLink(DataType x,PNode p)//在单链表中p所指结点的后面插入元素x
{
    PNode q;
    q=(PNode)malloc(sizeof(Node));
    q->info=x;
    q->next=p->next;
    p->next=q;
}

PLinkList CreLink(int n)        //创建一个带头结点的空链表并插入元素
{
    int x;
    PNode p;
    PLinkList pllist;           //pllist是指向单链表的一个指针变量
    pllist=(PLinkList)malloc(sizeof(LinkList));
    p=(PNode)malloc(sizeof(Node));
    pllist->head=p;
    p->next=NULL;
    for(int i=0;i<n;i++){
        cin>>x;
        InsLink(x,p);
        p=p->next;
    }
    p->next=NULL;
    return pllist;
}

PNode Findx(PLinkList pllist,DataType x)    //在pllist所指的带有头结点的单链表中找元素为x的结点位置
{
    PNode p;
    p=pllist->head->next;
    while(p!=NULL&&p->info!=x)p=p->next;
    return p;
}

void DelLink(PLinkList pllist, DataType x)  //在pllist所指的带有头结点的单链表中删除元素为x的结点
{
    PNode q,p=pllist->head;                 //在pllist所指的带有头结点的单链表中找元素为x的结点的前驱结点位置
    while(p->next!=NULL&&p->next->info!=x)p=p->next;
    if(p->next==NULL)cout<<"Not exist!\n";  //没找到元素为x的结点
    else{
        q=p->next;                          //找到元素为x的结点则删除
        p->next=q->next;
        free(q);
    }
}

void DelNode(PLinkList la,PLinkList lb,PLinkList lc)
{
    PNode p=la->head->next;
    while(p){
        int x=p->info;
        if(Findx(lb,x)&&Findx(lc,x))DelLink(la,x);
        p=p->next;
    }
}

void Display(PLinkList pllist)
{
    PNode p=pllist->head->next;
    while(p){
        cout<<(p->info)<<" ";
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    int m,n,p;
    PLinkList a,b,c;
    cin>>m>>n>>p;
    a=CreLink(m);
    b=CreLink(n);
    c=CreLink(p);
    DelNode(a,b,c);
    Display(a);
    return 0;
}
