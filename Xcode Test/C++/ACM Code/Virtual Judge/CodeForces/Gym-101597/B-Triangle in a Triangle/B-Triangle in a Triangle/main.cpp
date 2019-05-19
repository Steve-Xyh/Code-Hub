//  Gym-101597B
//  main.cpp
//  B-Triangle in a Triangle
//  https://vjudge.net/contest/220847#problem/B
//  Created by Steve X on 2018/4/7.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:求凸包顶点后暴力枚举3个点,S=1/2absin<a,b>=1/2axb

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 1000010

using namespace std;

struct point{
    double x,y;
};
bool mult(point sp,point ep,point op)
{
    return (sp.x-op.x)*(ep.y-op.y)
    >(ep.x-op.x)*(sp.y-op.y);               //加上等号为包括共线情况
}
bool operator < (const point &l,const point &r)
{
    return l.y<r.y||(l.y==r.y&&l.x<r.x);
}

int cnt=0;
point a,b,c,pnt[N],res[N];

int graham(point pnt[],int n,point res[])   //求凸包,pnt为原始点集,res为凸包点集
{
    int i,len,top=1;
    sort(pnt,pnt+n);
    if(n==0)return 0;res[0]=pnt[0];
    if(n==1)return 1;res[1]=pnt[1];
    if(n==2)return 2;res[2]=pnt[2];
    for(i=2;i<n;i++){
        while(top&&mult(pnt[i],res[top],res[top-1]))
            top--;
        res[++top]=pnt[i];
    }
    len=top;res[++top]=pnt[n-2];
    for(i=n-3;i>=0;i--){
        while(top!=len&&mult(pnt[i],res[top],res[top-1]))
            top--;
        res[++top]=pnt[i];
    }
    return top;                             //凸包顶点个数
}

double xmulti(point p1,point p2,point p0){  //叉积
    return((p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y));
}

double pntlen(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

point calpoint(point a,point b,int d)       //求点的位置
{
    point p;
    double k=d*1.0/pntlen(a,b);
    p.x=k*(b.x-a.x)+a.x;
    p.y=k*(b.y-a.y)+a.y;
    return p;
}

void cinpoint(point &p)
{
    cin>>p.x>>p.y;
}

void cinedge(point a,point b)
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int d;
        cin>>d;
        pnt[cnt++]=calpoint(a,b,d);
    }
}

double CalMaxS(int sum)                     //暴力求最大面积
{
    double maxs=0;
    for(int i=0;i<sum;i++){
        for(int j=i+1;j<sum;j++){
            for(int k=j+1;k<sum;k++){
                maxs=max(maxs,xmulti(res[i],res[j],res[k])/2.0);
            }
        }
    }
    return maxs;
}

int main()
{
    cinpoint(a);
    cinpoint(b);
    cinpoint(c);
    cinedge(a,b);
    cinedge(b,c);
    cinedge(c,a);
    int sum=graham(pnt,cnt,res);
    printf("%f\n",CalMaxS(sum));
    return 0;
}
