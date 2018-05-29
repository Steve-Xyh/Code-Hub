//  单链表的归并(耿2.11)
//  main.cpp
//  NOJ-DS 4 next merge
//
//  Created by Steve X on 2018/3/17.
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

void Display(PLinkList pllist)
{
    PNode p=pllist->head->next;
    while(p){
        cout<<(p->info)<<" ";
        p=p->next;
    }
    cout<<endl;
}

void MergeList(LinkList la,LinkList lb,PLinkList lc)
{
    PNode pa,pb,pc;
    pa=la.head->next;
    pb=lb.head->next;
    /*pa=la.head;pb=lb.head;
    //lc->head=pc=pa;*/
    //lc->head=pc=(PNode)malloc(sizeof(Node));
    lc->head=pc=la.head;          //pc指向la头结点
    while(pa&&pb){
        if(pa->info<=pb->info){
            pc->next=pa;pc=pa;pa=pa->next;
        }
        else{
            pc->next=pb;pc=pb;pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;
}

void Reverselist(PLinkList pllist)
{
    PNode p=pllist->head->next;
    PNode q=NULL;
    pllist->head->next=NULL;
    while(p){
        PNode r=p->next;
        p->next=q;
        q=p;
        p=r;
    }
    pllist->head->next=q;
}

int main()
{
    int m,n;
    cin>>m>>n;
    PLinkList a,b,c;
    LinkList la,lb;
    a=CreLink(m);
    b=CreLink(n);
    la.head=a->head;
    lb.head=b->head;
    c=(PLinkList)malloc(sizeof(LinkList));
    MergeList(la,lb,c);
    Reverselist(c);
    Display(c);
    return 0;
}
