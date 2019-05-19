//  [NWPU2018]组队训练赛第五场  ##DNF##
//  main.cpp
//  C-Empty Convex Polygons
//  https://vjudge.net/contest/250973#problem/C
//  Created by Steve X on 2018/8/30.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:凸包+多边形面积

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#define N 100

using namespace std;

struct point{
    int x,y;
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

void cinpoint(point &p)
{
    cin>>p.x>>p.y;
}
//------------------------------------------//求凸包
double areaofp(int vcount,point plg[])      //求凸多边形面积
{
    double s;
    if(vcount<3)return 0;
    s=plg[0].y*(plg[vcount-1].x-plg[1].x);
    for(int i=1;i<vcount;i++)s+=plg[i].y*(plg[(i-1)].x-plg[(i+1)%vcount].x);
    return s/2;
}

int main()
{
    int T,n,vcount;
    cin>>T;
    while(T--){
        cin>>n;
        memset(pnt,0,sizeof(pnt));
        memset(res,0,sizeof(res));
        for(int i=0;i<n;i++)cinpoint(pnt[i]);
        vcount=graham(pnt,n,res);
        double ans=areaofp(vcount,res);
        printf("%.1f\n",ans);
    }
    return 0;
}
