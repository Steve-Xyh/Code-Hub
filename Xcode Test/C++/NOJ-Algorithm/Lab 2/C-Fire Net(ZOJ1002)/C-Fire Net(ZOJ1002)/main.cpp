//
//  main.cpp
//  C-Fire Net(ZOJ1002)
//
//  Created by Steve X on 2018/11/14.
//  Copyright © 2018 Steve X. All rights reserved.
//  Methods:DFS(从左上角开始搜索,判断位置时从右下角开始检查,使防火墙起作用)
//  堡垒问题
#include <iostream>
#include <algorithm>
using namespace std;

const int N=5;
char map[N][N];
int n,ans;

void init()                                 //Initialize the map
{
    ans=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)map[i][j]='.';
}

bool place(int row,int col)                 //Able to place at point(row,col)
{
    for(int i=row-1;i>=0;i--){              //Search as row(only i-- from bottom-right,not i++)
        if(map[i][col]=='X')break;          //Wall
        if(map[i][col]=='o')return false;   //Occupied point
    }
    for(int i=col-1;i>=0;i--){              //Search as column(only i--,not i++)
        if(map[row][i]=='X')break;
        if(map[row][i]=='o')return false;
    }
    return true;
}

void dfs(int k,int cnt)
{
    int x,y;
    if(k>=n*n)ans=max(ans,cnt);
    else{
        x=k/n;
        y=k%n;
        if((map[x][y]=='.')&&place(x,y)){
            map[x][y]='o';
            dfs(k+1,cnt+1);
            map[x][y]='.';                  //DFS reverse changes
        }
        dfs(k+1,cnt);
    }
}

int main()
{
    while((cin>>n)&&n){
        init();
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)cin>>map[i][j];
        dfs(0,0);
        cout<<ans<<endl;
    }
    
    return 0;
}
