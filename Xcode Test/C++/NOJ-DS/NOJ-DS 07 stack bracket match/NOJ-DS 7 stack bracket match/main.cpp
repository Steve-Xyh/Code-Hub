//  表达式括号匹配(严3.19)
//  main.cpp
//  NOJ-DS 7 stack bracket match
//
//  Created by Steve X on 2018/3/22.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <stack>
#define N 100
using namespace std;

typedef char DataType;

int bkt(DataType x)
{
    switch (x){
        case '{':return 1;
        case '}':return 2;
        case '[':return 3;
        case ']':return 4;
        case '(':return 5;
        case ')':return 6;
    }
    return 0;
}

int judge(DataType a[N])
{
    stack<DataType>s;
    for(int i=0;i<N&&a[i];i++){
        if(bkt(a[i])){
            if(s.empty()&&!bkt(a[i])%2)return 0; //如果右括号先入则配对错误
            if(s.empty()||(bkt(s.top())+1)!=bkt(a[i]))s.push(a[i]);
            else s.pop();
        }
    }
    if(s.empty())return 1;
    else return 0;
}

int main()
{
    DataType a[N];
    cin>>a;
    if(judge(a))cout<<"yes\n";
    else cout<<"no\n";
    return 0;
}
