//  ##DFS## ##深搜##
//  main.cpp
//  POJ-2386 Lake Counting
//  https://vjudge.net/problem/POJ-2386
//  Created by Steve X on 2018/11/17.
//  Copyright © 2018 Steve X. All rights reserved.
//  Methods:DFS

#include <iostream>
using namespace std;

const int N=110;
int m,n;
char lake[N][N];                        //The map of lakes

bool water(int x,int y)                 //A valid point which has water
{
    if(0<=x&&x<n&&0<=y&&y<m&&lake[x][y]=='W')return true;
    return false;
}

void dfs(int x,int y)
{
    lake[x][y]='.';                     //Replace current point with '.'
    for(int dx=-1;dx<=1;dx++){          //Move to 8 directions around
        for(int dy=-1;dy<=1;dy++){
            int nx=x+dx,ny=y+dy;        //Move dx to x,dy to y
            if(water(nx,ny))dfs(nx,ny);
        }
    }
}

int solve()
{
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(water(i,j)){             //Find a point of water and DFS
                dfs(i,j);
                cnt++;                  //The ans is the times of DFS
            }
        }
    }
    return cnt;
}

int main()
{
    while(cin>>n>>m){
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)cin>>lake[i][j];
        cout<<solve()<<endl;
    }
    return 0;
}
