//  HDU-1004
//  main.cpp
//  A-STL map1
//  https://vjudge.net/contest/205706#problem/A
//  Created by Steve X on 2018/2/21.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:STL的map

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n;
    string str,ans;
    map<string,int>a;
    while(cin>>n&&n){
        int maxv=0;
        for(int i=0;i<n;i++){
            cin>>str;
            if(!a.count(str))a[str]=0;  //a.count(str)存在a[str]返回1,不存在返回0
            a[str]++;                   //str出现次数++
            if(a[str]>maxv){            //找出出现次数最多的str
                maxv=a[str];
                ans=str;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
