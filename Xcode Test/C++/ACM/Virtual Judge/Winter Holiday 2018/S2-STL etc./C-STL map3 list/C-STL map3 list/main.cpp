//
//  main.cpp
//  C-STL map3 list
//  https://vjudge.net/contest/205706#problem/C
//  Created by Steve X on 2018/2/21.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:二维map,迭代器的使用

#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int cnt;
string loc,name;

void createlist(int n,map<string,map<string,int>>&a)//输入记录,引用a/***/
{
    while(n--){
        cin>>name>>loc>>cnt;                        //名称,产地,数量
        a[loc][name]+=cnt;
    }
}

void disp(map<string,map<string,int>>a)             //输出归纳好的清单
{
    map<string,map<string,int>>::iterator i;
    for(i=a.begin();i!=a.end();i++){
        cout<<i->first<<endl;
        map<string,int>::iterator j;
        for(j=i->second.begin();j!=i->second.end();j++){
            cout<<"   |----"<<j->first<<"("<<j->second<<")"<<endl;
        }
    }
}

int main()
{
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        map<string,map<string,int>>a;               //每组初始化
        createlist(n,a);
        disp(a);
        if(T)cout<<endl;
    }
    return 0;
}
