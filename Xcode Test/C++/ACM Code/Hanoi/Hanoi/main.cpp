//  OpenJ_Bailian - 4147  n层汉诺塔的移动方法
//  main.cpp
//  Hanoi
//
//  Created by Steve X on 2018/1/26.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:递归

#include <iostream>
using namespace std;

int num=0;

void Hanoi(int n,char x,char y,char z)      //n层,从x借助y移动到z
{
    if(n==1)cout<<++num<<"#  "<<"1:"<<x<<"->"<<z<<endl;   //当只有1层时,直接从x移动到z
    else{
        Hanoi(n-1,x,z,y);                   //将n-1层从x借助z移动到y
        cout<<++num<<"#  "<<n<<":"<<x<<"->"<<z<<endl;     //将第n层从x移动到y
        Hanoi(n-1,y,x,z);                   //将n-1层从y借助x移动到z
    }
}

int main()
{
    int n;
    char x,y,z;
    cin>>n>>x>>y>>z;
    Hanoi(n,x,y,z);
    return 0;
}
