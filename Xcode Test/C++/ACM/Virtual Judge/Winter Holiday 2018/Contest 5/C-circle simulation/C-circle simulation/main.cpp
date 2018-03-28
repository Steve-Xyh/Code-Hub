//  51Nod-1875
//  main.cpp
//  C-circle simulation
//  https://vjudge.net/contest/207828#problem/C
//  Created by Steve X on 2018/2/8.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:打表

#include <iostream>
using namespace std;

int num[15];
int judge(int g,int e)
{
    int c=2*g,tag=1;
    for(int i=0;i<g;i++){
        tag=(tag+e-1)%c;
        if(tag==0)tag=c;
        if(tag<=g)return 0;
        c--;
    }
    return 1;
}

void createlist()
{
    for(int i=1;i<14;i++){
        int e=1;
        while(!judge(i,e))e++;
        num[i]=e;
    }
}

int main()
{
    int g;
    createlist();
    while(cin>>g&&g)cout<<num[g]<<endl;
    return 0;
}
