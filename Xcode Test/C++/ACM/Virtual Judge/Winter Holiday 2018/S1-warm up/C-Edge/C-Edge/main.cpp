//  https://vjudge.net/contest/205705#problem/C
//  main.cpp
//  C-Edge
//
//  Created by Steve X on 2018/1/27.
//  Copyright © 2018年 Steve X. All rights reserved.
//  {0,1,2,3}==右,下,左,上

#include <iostream>
#include <cstdio>
#include <cstring>
#define N 200
using namespace std;

int direction(int n,char c[])
{
    int dir=0;
    for(int i=0;i<n;i++){
        if(c[i]=='A')dir=(dir+1)%4;                    //顺时针+1,逆时针-1
        if(c[i]=='V')dir=dir>0?((dir-1)%4):3;
    }
    return dir;
}

void moveto(int &x,int &y,int dir)                     //引用x,y,改变坐标
{
    switch (dir){
        case 0:x+=10;break;
        case 1:y-=10;break;
        case 2:x-=10;break;
        case 3:y+=10;break;
    }
    cout<<x<<" "<<y<<" lineto"<<endl;
}

void showmove(int x,int y,char c[])
{
    int cnt=int(strlen(c));
    for(int i=1;i<=cnt;i++)moveto(x,y,direction(i,c));
}

int main()
{
    char c[N];
    while(~scanf("%s",c)){
        int x=310,y=420;                               //初始从(300,420)向右走至(310,420)
        cout<<"300 420 moveto\n310 420 lineto"<<endl;
        showmove(x,y,c);
        cout<<"stroke\nshowpage\n";
    }
    return 0;
}
