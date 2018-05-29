//  LOCATE操作(严2.38)
//  main.cpp
//  NOJ-DS 6 cdbLink sort
//
//  Created by Steve X on 2018/3/21.
//  Copyright © 2018年 Steve X. All rights reserved.
//  链表排序(双向循环链表)

#include <iostream>
#include <cstdlib>
using namespace std;

typedef char DataType;
typedef struct DbNode{
    int freq;                //访问频数freq
    DataType info;
    DbNode *llink,*rlink;
}*PDbNode;

typedef struct DbLinkList{   //双向链表类型
    PDbNode  head;           //指向第一个结点
    PDbNode  tail;           //指向最后一个结点
}*PDbLinkList;
//PDbLinkList  pdlist;       //pdlist是指向双链表类型的指针变量

void InsDbLink(PDbLinkList pdlist,PDbNode p,DataType x)
{                            //在双链表pdlist中p后插入x
    PDbNode s;
    s=(PDbNode)malloc(sizeof(DbNode));
    s->info=x;
    s->freq=0;
    s->rlink=p->rlink;
    p->rlink->llink=s;
    s->llink=p;
    p->rlink=s;
}

void InsDbNode(PDbLinkList pdlist,PDbNode p,PDbNode s)
{                            //双链表pdlist中p后插入结点s
    s->rlink=p->rlink;
    p->rlink->llink=s;
    s->llink=p;
    p->rlink=s;
}

void DelDbLink(PDbLinkList pdlist,PDbNode p)
{                            //删除带头结点的双链表pllist中的p元素
    p->llink->rlink=p->rlink;
    p->rlink->llink=p->llink;
    free(p);
}

PDbLinkList CreLink(int n)   //创建一个带头结点的空链表并插入元素x
{
    DataType x;
    PDbNode p;
    PDbLinkList pdlist;      //pdlist是指向双链表的一个指针变量
    pdlist=(PDbLinkList)malloc(sizeof(DbLinkList));
    p=(PDbNode)malloc(sizeof(DbNode));
    pdlist->head=p;
    pdlist->tail=p;
    p->rlink=pdlist->head;
    p->llink=pdlist->tail;
    for(int i=0;i<n;i++){
        cin>>x;
        InsDbLink(pdlist,p,x);
        p=p->rlink;
    }
    p->rlink=pdlist->head;
    return pdlist;
}

PDbNode Findx(PDbLinkList pdlist,DataType x)
{                            //在pdlist中找元素为x的结点位置
    PDbNode p;
    p=pdlist->head->rlink;
    while(p!=pdlist->tail&&p->info!=x)p=p->rlink;
    return p;
}

void VisDbNode(PDbLinkList pdlist,DataType x)
{
    PDbNode t=(PDbNode)malloc(sizeof(DbNode));
    PDbNode p=Findx(pdlist,x),q=pdlist->head->rlink;
    p->freq++;
    t->info=p->info;
    t->freq=p->freq;
    DelDbLink(pdlist,p);     //频数最高的结点排在最前
    while(t->freq<=q->freq&&q!=pdlist->tail)q=q->rlink;
    InsDbNode(pdlist,q->llink,t);
}

void Display(PDbLinkList pdlist)
{
    PDbNode p=pdlist->head->rlink;
    while(p!=pdlist->tail){
        cout<<(p->info)<<" ";
        p=p->rlink;
    }
    cout<<endl;
}

int main()
{
    int m,n;
    DataType x;
    cin>>m>>n;
    PDbLinkList la=CreLink(m);
    while(n--){
        cin>>x;
        VisDbNode(la,x);
    }
    Display(la);
    return 0;
}
