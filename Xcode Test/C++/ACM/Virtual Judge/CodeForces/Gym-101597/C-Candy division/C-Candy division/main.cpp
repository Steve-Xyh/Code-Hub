//  Gym-101597
//  main.cpp
//  C-Candy division
//  https://vjudge.net/contest/220847#problem/C
//  Created by Steve X on 2018/4/8.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:全靠蒙

#include <iostream>

using namespace std;

void judge(long long n)
{
    if(n%3==0){
        cout<<n/3<<" "<<n/3<<" "<<n/3<<endl;
        return;
    }
    if(n%4==0){
        cout<<n/2<<" "<<n/4<<" "<<n/4<<endl;
        return;
    }
    else cout<<"IMPOSSIBLE\n";
}

int main()
{
    int T;
    long long n;
    cin>>T;
    while(T--){
        cin>>n;
        judge(n);
    }
    return 0;
}
