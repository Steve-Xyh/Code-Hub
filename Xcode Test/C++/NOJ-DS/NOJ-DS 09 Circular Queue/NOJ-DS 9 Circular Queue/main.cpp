//  循环队列(严3.30)
//  main.cpp
//  NOJ-DS 9 Circular Queue
//
//  Created by Steve X on 2018/5/23.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAXNUM  100
using namespace std;

typedef int DataType;

typedef struct SeqQueue{        //顺序队列类型定义
    DataType q[MAXNUM];
    int front,rear,length,cnt;
}*PSeqQueue;                    //顺序队列类型的指针类型

PSeqQueue CrtEptQueue(int len)  //创建长度为n的循环队列
{
    PSeqQueue paqu=(PSeqQueue)malloc(sizeof(SeqQueue));
    paqu->front=0;
    paqu->rear=0;
    paqu->length=len;
    paqu->cnt=0;
    return paqu;
}

bool isEptQueue(PSeqQueue paqu) //判断是否为空
{
    return paqu->front==paqu->rear;
}

bool isFullQueue(PSeqQueue paqu)//判断是否为满
{
    return paqu->length==paqu->cnt;
}

void EnQueue(PSeqQueue paqu,DataType x)
{                               //在队列尾部插入一元素x
    paqu->q[paqu->rear]=x;
    paqu->rear=(paqu->rear+1)%paqu->length;
    paqu->cnt++;
}

void DeQueue(PSeqQueue paqu)    //删除队列头部元素
{
    paqu->front=(paqu->front+1)%paqu->length;
    paqu->cnt--;
}

DataType FrtElmt(PSeqQueue paqu)//对非空队列，求队列头部元素
{
    return paqu->q[paqu->front];
}

void CinQueue(PSeqQueue p,int n)//输入n个元素至队列
{
    DataType x;
    p->cnt=0;
    for(int i=0;i<n;i++){
        cin>>x;
        if(x)EnQueue(p,x);
        if(getchar()=='\n')return;
    }
}

DataType DltElmt(PSeqQueue p,DataType out)
{                               //将元素out出队,并返回队首元素
    while(1){
        DeQueue(p);
        if(FrtElmt(p)==out){
            DeQueue(p);
            break;
        }
    }
    return FrtElmt(p);
}

int main()
{
    int n;
    string s;
    PSeqQueue p;
    DataType out,front;
    cin>>n;
    p=CrtEptQueue(n);
    CinQueue(p,n);
    cin>>s;
    //if(isFullQueue(p))cout<<"yes"<<endl;
    //else cout<<"no"<<endl;
    cin>>out;
    front=DltElmt(p,out);
    while(p->cnt){
        cout<<FrtElmt(p);
        DeQueue(p);
        if(p->cnt)cout<<" ";
    }
    cout<<endl<<front<<endl;
    return 0;
}
