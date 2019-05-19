//  CodeForces-347C
//  main.cpp
//  B-game
//  https://vjudge.net/contest/209734#problem/B
//  Created by Steve X on 2018/2/9.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:set中元素可构成等差数列时结束游戏

#include <iostream>
#include <algorithm>
#define N 100000+10
using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
    int n,a[N];
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>a[i];    //an为等差数列时结束游戏
        sort(a,a+n);                      //必须排序,找最大元素a[n-1]
        int d=a[0],cnt;
        for(int i=0;i<n;i++)d=gcd(d,a[i]);//公差d为gcd(a[])
        cnt=a[n-1]/d-n;                   //游戏进行次数为等差数列an的项数-n
        if(cnt&1)cout<<"Alice"<<endl;     //Alice先出,奇数次为Alice赢,偶数次Bob赢
        else cout<<"Bob"<<endl;
    }
    return 0;
}
