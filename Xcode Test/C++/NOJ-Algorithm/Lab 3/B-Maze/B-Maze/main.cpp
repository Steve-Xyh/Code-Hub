//
//  main.cpp
//  B-Maze
//
//  Created by Steve X on 2018/11/17.
//  Copyright © 2018 Steve X. All rights reserved.
//
//  电子老鼠创迷宫
#include <iostream>
#include <queue>
using namespace std;

const int N=12,INF=1e8;
int d[N][N];                            //distance to start point
int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};  //4 directions
char maze[N][N];


typedef pair<int,int> Point;
Point st,goal;
queue<Point> q;

void init()
{
    q.push(st);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)d[i][j]=INF;
    d[st.first][st.second]=0;
}

bool canMove(int x,int y)
{
    if(0<=x&&x<N&&0<=y&&y<N&&maze[x][y]!='X')return true;
    else return false;
}

bool vis(int x,int y)
{
    if(d[x][y]!=INF)return true;    //visited
    else return false;              //not visited
}

int bfs()
{
    init();
    while(1){
        Point p=q.front();
        q.pop();
        if(p==goal)break;           //Reach goal,stop searching
        for(int i=0;i<4;i++){       //New x,y
            int nx=p.first+dx[i],ny=p.second+dy[i];
            if(canMove(nx,ny)&&(!vis(nx,ny))){
                q.push(Point(nx,ny));
                d[nx][ny]=d[p.first][p.second]+1;
            }
        }
    }
    return d[goal.first][goal.second];
}

void input()
{
    cin>>st.first>>st.second>>goal.first>>goal.second;
    st.first--;st.second--;
    goal.first--;goal.second--;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)cin>>maze[i][j];
}

int main()
{
    input();
    cout<<bfs()<<endl;
    return 0;
}
