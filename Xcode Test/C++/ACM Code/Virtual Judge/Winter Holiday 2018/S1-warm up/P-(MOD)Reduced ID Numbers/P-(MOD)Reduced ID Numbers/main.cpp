//
//  main.cpp
//  P-(MOD)Reduced ID Numbers
//  https://vjudge.net/contest/205705#problem/P
//  Created by Steve X on 2018/2/19.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:找出一组数不两两不同余m的最小m值,暴力

#include <iostream>
#include <cstring>
#define N 100010
using namespace std;
int a[300],mod[N];

int judge(int a[],int n,int m)
{
    memset(mod,0,sizeof(int)*m);     //a[i]%m<m,只需将前m个数清零
    for(int i=0;i<n;i++){
        if(mod[a[i]%m])return 0;     //如果此余数出现过则同余,返回0
        else mod[a[i]%m]=1;          //如果此余数没出现过,则标记为1
    }
    return 1;                        //两两不同余,返回1
}

int main()
{
    int T,n,maxv;
    cin>>T;
    while(T--){
        maxv=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i];
            maxv=maxv>a[i]?maxv:a[i];
        }
        for(int i=n;i<=maxv+1;i++){  //据说模数不小于n
            if(judge(a,n,i)){
                cout<<i<<endl;
                break;
            }
        }
    }
    return 0;
}
