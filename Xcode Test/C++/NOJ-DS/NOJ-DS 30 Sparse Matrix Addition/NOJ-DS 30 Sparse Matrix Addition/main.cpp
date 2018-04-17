//  实验2.2 稀疏矩阵加法,实现C=A+B
//  main.cpp
//  NOJ-DS 30 Sparse Matrix Addition
//
//  Created by Steve X on 2018/4/16.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#define MaxSize 1000
using namespace std;

typedef int ElemType;
typedef struct{
    int i,j;            //行号和列号
    ElemType elem;      //元素值
}Triple;

typedef struct{
    Triple data[MaxSize];
    int m,n,t;          //行数,列数和非零元个数
}TSMatrix;

void CinMatrix(TSMatrix &M)
{                       //输入稀疏矩阵
    for(int i=0;i<M.t;i++)cin>>M.data[i].i>>M.data[i].j>>M.data[i].elem;
}

bool operator == (const Triple &a,const Triple &b)
{
    return a.i==b.i&&a.j==b.j;
}

bool operator < (const Triple &a,const Triple &b)
{
    return a.i<b.i||(a.i==b.i&&a.j<=b.j);
}

TSMatrix MatAdd(TSMatrix a,TSMatrix b)  //稀疏矩阵加法
{
    TSMatrix c;
    c.t=0;
    int ia=0,ib=0;
    while(ia<a.t&&ib<b.t){
        if(a.data[ia]==b.data[ib]){
            int i=a.data[ia].i,j=a.data[ia].j;
            int tmp=a.data[ia++].elem+b.data[ib++].elem;
            if(tmp){                    //只记录非零元
                c.data[c.t].i=i;
                c.data[c.t].j=j;
                c.data[c.t++].elem=tmp;
            }
        }
        else if(a.data[ia]<b.data[ib])c.data[c.t++]=a.data[ia++];
        else c.data[c.t++]=b.data[ib++];//空白处按顺序添加非零元
    }
    return c;
}

void DispSMatrix(TSMatrix M)            //输出稀疏矩阵
{
    for(int i=0;i<M.t;i++)cout<<M.data[i].i<<" "<<M.data[i].j<<" "<<M.data[i].elem<<endl;
}

int main()
{
    int m,n;
    TSMatrix a,b,c;
    cin>>m>>n>>a.t>>b.t;
    a.m=b.m=c.m=m;
    a.n=b.n=c.n=n;
    CinMatrix(a);
    CinMatrix(b);
    c=MatAdd(a,b);
    DispSMatrix(c);
    return 0;
}
