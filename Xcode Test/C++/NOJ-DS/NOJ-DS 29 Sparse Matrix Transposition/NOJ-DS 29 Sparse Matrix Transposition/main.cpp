//  实验2.1 稀疏矩阵转置
//  main.cpp
//  NOJ-DS 29 Sparse Matrix Transposition
//
//  Created by Steve X on 2018/4/9.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define MaxSize 1000
using namespace std;

typedef int ElemType;
typedef struct{
    int i,j;            //行号和列号
    ElemType elem;      //元素值
}Triple;                //三元组

bool cmp(Triple a,Triple b)
{
    return a.i<b.i||(a.i==b.i&&a.j<b.j);
}

int main()
{
    int i,j,x,cnt=0;
    Triple a[MaxSize];
    cin>>i>>j;
    while(cin>>i>>j>>x&&(i||j||x)){
        a[cnt].i=j;
        a[cnt].j=i;
        a[cnt++].elem=x;
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++)cout<<a[i].i<<" "<<a[i].j<<" "<<a[i].elem<<endl;
}















/*
typedef struct{
    Triple data[MaxSize];
    int m,n,t;          //行数,列数和非零元个数
}TSMatrix;

void CinMatrix(TSMatrix &M)
{                       //输入稀疏矩阵
    int a,b;
    ElemType c;
    M.t=0;
    while(cin>>a>>b>>c&&a!=0&&b!=0&&c!=0){
        M.data[M.t].i=a;
        M.data[M.t].j=b;
        M.data[M.t].elem=c;
        M.t++;
    }
}

int num[MaxSize],cpot[MaxSize];
TSMatrix FastTransposeSMatrix(TSMatrix M)
{
    int col,p,q,t;
    TSMatrix T;
    T.m=M.n;T.n=M.m; T.t=M.t;
    if(T.t){
        for(col=0;col<M.n;++col)num[col]=0;
        for(t=0;t<M.t;++t)++num[M.data[t].j];   //统计每列的非零元个数
        cpot[0]=0;                              //计算每列第一个非零元转置后的位置
        for(col=1;col<M.n;++col)cpot[col]=cpot[col-1]+num[col-1];
        for(p=0;p<M.t;++p){
            col=M.data[p].j;q=cpot[col];
            T.data[q].i=M.data[p].j;T.data[q].j=M.data[p].i;
            T.data[q].elem=M.data[p].elem;
            ++cpot[col];
        }
    }
    return T;
}

void DispSMatrix(TSMatrix M)
{                       //输出稀疏矩阵
    for(int i=0;i<M.t;i++)cout<<M.data[i].i<<" "<<M.data[i].j<<" "<<M.data[i].elem<<endl;
}

bool cmp(Triple a,Triple b)
{
    return a.i<b.i||(a.i==b.i&&a.j<=b.j);
}

void TransSMatrix(TSMatrix &M)
{                       //转置,交换行,列号
    for(int i=0;i<M.t;i++){
        M.data[i].i^=M.data[i].j;
        M.data[i].j^=M.data[i].i;
        M.data[i].i^=M.data[i].j;
    }
    sort(M.data,M.data+M.t,cmp);
    M.m^=M.n;
    M.n^=M.m;
    M.m^=M.n;
}

void DispMatrix(TSMatrix M)
{                       //输出完整矩阵
    int t=0;
    for(int i=1;i<=M.m;i++){
        for(int j=1;j<=M.n;j++){
            //if(j!=1)cout<<" ";
            if(i==M.data[t].i&&j==M.data[t].j){
                cout<<M.data[t].elem<<" ";
                t++;
            }
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    TSMatrix M,T;
    cin>>M.m>>M.n;
    CinMatrix(M);
    //TransSMatrix(M);
    T=FastTransposeSMatrix(M);
    DispSMatrix(T);
    //DispMatrix(T);
    return 0;
}*/
