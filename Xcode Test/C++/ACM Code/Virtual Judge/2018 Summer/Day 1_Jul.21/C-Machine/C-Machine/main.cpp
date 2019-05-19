//  Day 1
//  main.cpp
//  C-Machine
//  https://vjudge.net/contest/239961#problem/C
//  Created by Steve X on 2018/7/21.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:long long,3进制,0-R,1-G,2-B

#include <iostream>
using namespace std;

const int N=100;
const int k=3;
int bulb[N];

void transTo3(int a[],long long n)  //转为3进制
{
    int tag=N-1;
    for(int i=0;i<N;i++)a[i]=0;
    while(n){
        a[tag--]=n%k;
        n/=k;
    }
}

void display(int a[],int n)         //3进制,012分别代表RGB
{
    for(int i=N-n;i<N;i++){
        switch(a[i]){
            case 0:cout<<"R";break;
            case 1:cout<<"G";break;
            case 2:cout<<"B";break;
        }
    }
    cout<<endl;
}

int main()
{
    int T,m;
    long long n;
    cin>>T;
    while(T--){
        cin>>m>>n;
        transTo3(bulb,n);
        display(bulb,m);
    }
    return 0;
}
