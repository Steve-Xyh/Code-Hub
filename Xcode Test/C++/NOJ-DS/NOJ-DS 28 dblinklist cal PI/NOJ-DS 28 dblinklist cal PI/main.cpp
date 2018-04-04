//  实验1.2 高精度计算Pi值
//  main.cpp
//  NOJ-DS 28 dblinklist cal PI
//
//  Created by Steve X on 2018/4/2.
//  Copyright © 2018年 Steve X. All rights reserved.
//  R(1)=2,R(n+1)=R(n)*n/(2*n+1),Pi=sum(R(i))

#include <iostream>
#include <cstdlib>
#define MAXN 1000
using namespace std;

typedef int DataType;
typedef struct DbNode{
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
        //cin>>x;
        x=0;
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

void Display(PDbLinkList pdlist,int n)
{                            //输出Pi
    cout<<"3.";
    PDbNode p=pdlist->head->rlink->rlink;
    while(p!=pdlist->tail&&n--){
        cout<<(p->info);
        p=p->rlink;
    }
    cout<<endl;
}

void Multi(PDbLinkList pdlist,int a)
{                            //大数乘法
    int r=0;
    PDbNode p=pdlist->tail->llink;
    while(p!=pdlist->head){
        p->info=p->info*a+r;
        r=p->info/10;
        p->info%=10;
        p=p->llink;
    }
}

void Addition(PDbLinkList a,PDbLinkList b)
{                            //大数加法
    int r=0;
    PDbNode p=a->tail->llink,q=b->tail->llink;
    while(p!=a->head){
        p->info+=q->info+r;
        r=p->info/10;
        p->info%=10;
        p=p->llink;
        q=q->llink;
    }
}

void Division(PDbLinkList pdlist,int a)
{                            //大数除以小数
    int r=0;
    PDbNode p=pdlist->head->rlink;
    while(p!=pdlist->tail){
        p->info+=r*10;
        r=p->info%a;
        p->info/=a;
        p=p->rlink;
    }
}

void CalPi(PDbLinkList pi,PDbLinkList R)
{                            //R(1)=2,R(n+1)=R(n)*n/(2*n+1),Pi=sum(R(i))
    R->head->rlink->info=2;  //首位设为2
    Addition(pi,R);
    for(int i=1;i<10*MAXN;i++){
        Multi(R,i);
        Division(R,(2*i)+1);
        Addition(pi,R);
    }
}

int main()
{
    int n;
    PDbLinkList pi=CreLink(MAXN),R=CreLink(MAXN);
    CalPi(pi,R);
    cin>>n;
    Display(pi,n);
    return 0;
}
