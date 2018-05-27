//  实验2.4 稀疏矩阵的乘法
//  main.cpp
//  NOJ-DS 32 Sparse Matrix Multiplication
//
//  Created by Steve X on 2018/4/18.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
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

bool operator == (const Triple &a,const Triple &b)
{                       //行列号相等,可加
    return a.i==b.i&&a.j==b.j;
}

bool abm(Triple a,Triple b)
{                       //可乘
    return a.j==b.i;
}

bool cmp(Triple a,Triple b)
{
    return a.i!=b.i?a.i<b.i:a.j<b.j;
}

void CinMatrix(TSMatrix &M)
{                       //输入稀疏矩阵
    int i,j,x;
    M.t=0;
    cin>>M.m>>M.n;
    while(cin>>i>>j>>x&&(i||j||x)){
        M.data[M.t].i=i;
        M.data[M.t].j=j;
        M.data[M.t++].elem=x;
    }
}

TSMatrix MatMulti(TSMatrix a,TSMatrix b)//稀疏矩阵乘法(暴力)
{
    TSMatrix c;
    c.m=a.m;c.n=b.n;c.t=0;
    memset(c.data,0,sizeof(Triple)*a.m*b.n);
    for(int ia=0;ia<a.t;ia++){
        for(int ib=0;ib<b.t;ib++){
            if(abm(a.data[ia],b.data[ib])){
                c.data[c.t].i=a.data[ia].i;
                c.data[c.t].j=b.data[ib].j;
                c.data[c.t].elem=a.data[ia].elem*b.data[ib].elem;
                for(int k=0;k<c.t;k++){
                    if(c.data[c.t]==c.data[k]){
                        c.data[k].elem+=c.data[c.t].elem;
                        c.t--;          //如果该位置有非零元,则相加,并将非零元个数-1
                    }
                }
                c.t++;
            }
        }
    }
    sort(c.data,c.data+c.t,cmp);
    return c;
}

void DispSMatrix(TSMatrix M)            //输出稀疏矩阵
{
    for(int i=0;i<M.t;i++)cout<<M.data[i].i<<" "<<M.data[i].j<<" "<<M.data[i].elem<<endl;
}

int main()
{
    TSMatrix a,b,c;
    CinMatrix(a);
    CinMatrix(b);
    c=MatMulti(a,b);
    DispSMatrix(c);
    return 0;
}
