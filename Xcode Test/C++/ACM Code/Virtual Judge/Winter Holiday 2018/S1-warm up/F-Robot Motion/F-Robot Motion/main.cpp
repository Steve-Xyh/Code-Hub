//  https://vjudge.net/contest/205705#problem/F
//  main.cpp
//  F-Robot Motion
//
//  Created by Steve X on 2018/1/28.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#define N 100
using namespace std;

struct robo{
    char c;                                   //指令
    int vis=0,no;                             //访问次数,序号
}a[N][N];

void robomove(int &x,int &y,robo &a)          //引用坐标进行一次移动
{
    if(a.c=='N')y--;
    if(a.c=='S')y++;
    if(a.c=='E')x++;
    if(a.c=='W')x--;
    a.vis++;
}

void maze(robo a[N][N],int row,int col,int n) //一个迷宫的一系列移动
{
    int i=0,j=n-1,step1=0,step2=0,loop=0;
    a[0][n-1].vis=1;
    while(1){
        robomove(j,i,a[i][j]);
        step1++;
        if(i<0||j<0||i>=row||j>=col)break;
        if(a[i][j].vis>0){
            loop++;
            step2=step1-a[i][j].no;           //回路的步数
            step1-=step2;                     //进入回路之前的步数
            break;
        }
        a[i][j].no=step1;
    }
    if(loop)cout<<step1<<" step(s) before a loop of "<<step2<<" step(s)\n";
    else cout<<step1<<" step(s) to exit\n";
}

int main()
{
    int row,col,n;
    while(cin>>row>>col&&row!=0&&col!=0){
        cin>>n;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                cin>>a[i][j].c;
                a[i][j].vis=0;
            }
        }
        maze(a,row,col,n);
    }
    return 0;
}
