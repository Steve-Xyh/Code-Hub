//  Gym-101597K
//  main.cpp
//  I-ACM
//  https://vjudge.net/contest/220847#problem/I
//  Created by Steve X on 2018/4/8.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:水题

#include <iostream>
#include <cstring>
#define N 1000010
using namespace std;

char a[N];

int judge(char a[])
{
    for(int i=0;a[i]!='\0'&&i<N;i++){
        if(i<(N-2)&&a[i+2]!='\0'&&a[i]=='A'){
            if(a[i+1]=='C'){
                if(a[i+2]=='M')return 1;
            }
        }
    }
    return 0;
}

int main()
{
    while(cin>>a){
        if(judge(a))cout<<"Fun!\n";
        else cout<<"boring...\n";
        memset(a,'\0',sizeof(a));
    }
    return 0;
}
