//  W
//  main.cpp
//  U-Long Distance Racing
//  https://vjudge.net/contest/205705#problem/U
//  Created by Steve X on 2018/2/20.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#define N 1000010
using namespace std;
int m,t,u,f,d;
char c[N];

int sumtime(char c)                    //计算每条路往返时间
{
    if(c=='u'||c=='d')return u+d;      //返回时上坡与下坡颠倒
    return 2*f;
}

void caldist(char c[])                 //计算最远距离
{
    int dis=0,sumt=0;
    for(int i=0;i<t;i++){
        cin>>c[i];
        sumt+=sumtime(c[i]);
        if(sumt<=m)dis++;              //如果时间够当前路径往返,则将当前路径包含进来
    }
    cout<<dis<<endl;
}

int main()
{
    while(cin>>m>>t>>u>>f>>d)caldist(c);
    return 0;
}
