//  ************************************************
//  main.cpp
//  X-STL stack train
//  https://vjudge.net/contest/205706#problem/X
//  Created by Steve X on 2018/2/25.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:STL stack的操作

#include<iostream>
#include<stack>
#define N 100
using namespace std;

char str1[N],str2[N];          //初始序列,目标序列
int n,i,j,k,dire[N];           //n为列车个数,dire表示方向,1进0出
stack<char>station;

void disp()
{
    int i=0,j=0,k=1;
    station.push(str1[0]);     //标记str1首元素进栈
    dire[0]=1;
    while(i<n&&j<n){           //如果栈顶元素与str2当前元素相等,则出栈,否则str1当前元素进栈
        if(station.size()&&station.top()==str2[j]){
            j++;
            station.pop();
            dire[k++]=0;
        }
        else{
            if(i==n)break;
            station.push(str1[++i]);
            dire[k++]=1;
        }
    }
    if(i==n)cout<<"No."<<endl; //i=n说明栈顶元素不等于str2当前元素,且str1元素都已入栈,得不到str2
    else{
        cout<<"Yes."<<endl;
        for(i=0; i<k; i++){
            if(dire[i])cout<<"in"<<endl;
            else cout<<"out"<<endl;
        }
    }
    cout<<"FINISH"<<endl;
}

int main()
{
    while(cin>>n>>str1>>str2)disp();
    return 0;
}
