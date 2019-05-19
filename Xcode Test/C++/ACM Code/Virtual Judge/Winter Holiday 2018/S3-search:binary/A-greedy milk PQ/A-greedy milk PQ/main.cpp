//  ************************************************
//  main.cpp
//  A-greedy milk PQ
//
//  Created by Steve X on 2018/2/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:贪心,优先队列.开始时间升序,优先队列结束时间早者优先,检查是否有结束的机器,若有则用此机器,否则加新机器。

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 60000
using namespace std;

int n,mac[N];
struct COW
{
    int l;   //开始时间
    int r;   //结束时间
    int num; //机器编号
    bool operator <(const COW &a)const
    {
        if(r==a.r)return l>a.l;
        else return r>a.r;
    }
}a[N];
bool cmp(COW a,COW b)
{
    if(a.l==b.l)return a.r<b.r;
    else return a.l<b.l;
}

priority_queue<COW> q;

void disp()
{
    sort(a,a+n,cmp);
    q.push(a[0]);
    int ans=1;
    mac[a[0].num]=1;
    for(int i=1;i<n;i++){
        if(!q.empty()&&q.top().r<a[i].l){
            mac[a[i].num]=mac[q.top().num];
            q.pop();
        }
        else{
            ans++;
            mac[a[i].num]=ans;
        }
        q.push(a[i]);
    }
    cout<<ans<<endl;
    for(int i=0;i<n;i++)cout<<mac[i]<<endl;
    while(!q.empty())q.pop();
}

int main()
{
    while(cin>>n){
        for(int i=0;i<n;i++){
            cin>>a[i].l>>a[i].r;
            a[i].num=i;
        }
        disp();
    }
    return 0;
}
