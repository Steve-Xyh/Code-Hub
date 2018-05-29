//  实验4.3 用弗洛伊德算法求赋权图的两点间的最短路径的长度
//  main.cpp
//  NOJ-DS 36 Floyd Algorithm
//
//  Created by Steve X on 2018/5/29.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:n次执行Dijkstra

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

int Dijkstra(int cost[][MAXN],int lowcost[],int n,int beg,int end)
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
        for(int i=0;i<n;i++)if(!vis[i]&&lowcost[k]+cost[k][i]<lowcost[i]){
            lowcost[i]=lowcost[k]+cost[k][i];
            pre[i]=k;
        }
    }
    return lowcost[end];                    //求beg->end最短路径
}

void cinMatrix(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)cin>>graph[i][j];
}

void Floyd(int n)
{
    int cnt,u,v;
    cin>>cnt;
    while(cnt--){
        cin>>u>>v;
        cout<<Dijkstra(graph,len,n,u,v)<<endl;
    }
}

int main()
{
    int n;
    cin>>n;
    cinMatrix(n);
    Floyd(n);
    return 0;
}
