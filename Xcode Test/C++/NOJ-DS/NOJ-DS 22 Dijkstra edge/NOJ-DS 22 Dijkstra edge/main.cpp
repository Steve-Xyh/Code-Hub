//  Dijkstra算法(严7.42)
//  main.cpp
//  NOJ-DS 22 Dijkstra edge
//
//  Created by Steve X on 2018/5/30.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:Dijkstra模版+sort排序边长

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

/*==================================================*\
 | Dijkstra O(E * log E)                            |
 | INIT: 调用init(nv, ne)读入边并初始化;               |
 | CALL: dijkstra(n, src); dist[i]为src到i最短距离    |
\*==================================================*/

#define E 200
#define V 200
#define typec int                   //type of cost

const typec inf = 0x3f3f3f3f;       //max of cost
typec cost[E], dist[V];
int e, pnt[E], nxt[E], head[V], previous[V], vis[V];
struct qnode {
    int v; typec c;
    qnode (int vv = 0, typec cc = 0) : v(vv), c(cc) {}
    bool operator < (const qnode& r) const { return c>r.c; }
};
struct edge{
    int u,v,cost;
    bool operator < (const edge& r) const { return cost<r.cost; }
}ed[E];


void dijkstra(int n, const int src){
    qnode mv;
    int i, j, k, pre;
    priority_queue<qnode> que;
    vis[src] = 1; dist[src] = 0;
    que.push(qnode(src, 0));
    for (pre = src, i=1; i<n; i++) {
        for (j = head[pre]; j != -1; j = nxt[j]) {
            k = pnt[j];
            if (vis[k] == 0 &&dist[pre] + cost[j] < dist[k]){
                dist[k] = dist[pre] + cost[j];
                que.push(qnode(pnt[j], dist[k]));
                previous[k] = pre;
            }
        }
        while (!que.empty() && vis[que.top().v] == 1)que.pop();
        if (que.empty()) break;
        mv = que.top(); que.pop();
        vis[pre = mv.v] = 1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++)if(i!=src){
        ed[cnt].u=src;
        ed[cnt].v=i;
        ed[cnt++].cost=dist[i];
    }
    sort(ed,ed+cnt);                //按src->i的距离升序排列
}

inline void addedge(int u, int v, typec c)
{
    pnt[e] = v; cost[e] = c; nxt[e] = head[u]; head[u] = e++;
}

void init(int nv, int ne){
    int i, u, v; typec c;
    e = 0;
    memset(head, -1, sizeof(head));
    memset(vis, 0, sizeof(vis));
    memset(previous, -1, sizeof(previous));
    for (i = 1; i <= nv; i++) dist[i] = inf;
    for (i = 1; i <= ne; ++i) {
        scanf("%d%d%d",&u,&v,&c);   //%d:typeofcost
        addedge(u, v, c);           // vertex: 0 ~ n-1, 单向边
    }
}

int main()
{
    int nv,ne;
    cin>>nv>>ne;
    init(nv,ne);
    dijkstra(nv,1);
    for(int i=0;i<nv-1;i++){
        if(ed[i].cost!=inf)cout<<ed[i].u<<" "<<ed[i].v<<" "<<ed[i].cost<<endl;
        else cout<<ed[i].u<<" "<<ed[i].v<<" "<<-1<<endl;
    }
}
