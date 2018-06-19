//  求广义表深度(严5.30)   ##special##
//  main.cpp
//  NOJ-DS 14 General List Depth
//
//  Created by Steve X on 2018/5/30.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
#define N 200
using namespace std;

int getDepth(char str[])
{
    int cnt=0,ans=0;
    for(int i=0;str[i]!='\0';i++){
        if(str[i]=='(')cnt++;       //左括号深度+1
        if(str[i]==')')cnt--;       //右括号深度-1
        ans=max(ans,cnt);           //深度取最大值
    }
    return ans;
}

int main()
{
    char s[N];
    cin>>s;
    cout<<getDepth(s)<<endl<<getDepth(s)<<endl;
    return 0;
}
