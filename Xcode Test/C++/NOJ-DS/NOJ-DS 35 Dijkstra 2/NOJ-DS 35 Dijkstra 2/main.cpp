//  实验4.2 用迪杰斯特拉算法求赋权图中的最短路径
//  main.cpp
//  NOJ-DS 35 Dijkstra 2
//
//  Created by Steve X on 2018/5/29.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:Dijkstra

#include <iostream>
using namespace std;

/*
 * kuangbin ACM
 * 单源最短路径,Dijkstra算法,邻接矩阵形式,复杂度为O(n^2)
 * 求出源beg到所有点的最短路径,传入图的顶点数,和邻接矩阵cost[][]
 * 返回各点的最短路径lowcost[],路径pre[i]记录beg到i路径上的父结点,pre[beg]=-1
 * 可更改路径权类型,但是权值必须为非负
 */

const int MAXN=1010;
const int INF=1e4;                          //防止后面溢出,这个不能太大,本题要求为10000
bool vis[MAXN];                             //vis[i]表示是否访问过结点i
int pre[MAXN],graph[MAXN][MAXN],len[MAXN];  //pre父亲结点,graph邻接矩阵,len[i]为beg到i最短路径

void display(int u,int v)
{
    if(pre[v]!=u)display(u,pre[v]);         //回溯输出u->v结点编号,形成最短路线
    else cout<<u<<endl;                     //先输出根结点u
    cout<<v<<endl;
}

void Dijkstra(int cost[][MAXN],int lowcost[],int n,int beg,int end)
{                                           //邻接矩阵cost,最短路径lowest,结点个数n,起始点beg,终点end
    for(int i=0;i<n;i++){
        lowcost[i]=INF;
        vis[i]=false;
        pre[i]=-1;
    }
    lowcost[beg]=0;
    for(int j=0;j<n;j++)
    {
        int k=-1,Min=INF;
        for(int i=0;i<n;i++)if(!vis[i]&&lowcost[i]<Min){
            Min=lowcost[i];
            k=i;
        }
        if(k==-1)break;
        vis[k]=true;
        if(k==end)break;                    //到达所求路线终点则停止查找
        for(int i=0;i<n;i++)
            if(!vis[i]&&lowcost[k]+cost[k][i]<lowcost[i]){
            lowcost[i]=lowcost[k]+cost[k][i];
            pre[i]=k;
        }
    }
    display(beg,end);
}

void cinMatrix(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)cin>>graph[i][j];
}

int main()
{
    int n,a,b;
    cin>>n;
    cinMatrix(n);
    cin>>a>>b;
    Dijkstra(graph,len,n,a,b);
    return 0;
}
