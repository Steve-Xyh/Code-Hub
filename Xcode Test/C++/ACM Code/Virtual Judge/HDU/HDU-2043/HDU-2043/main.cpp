//  密码
//  main.cpp
//  HDU-2043 Passcode
//  https://vjudge.net/problem/HDU-2043
//  Created by Steve X on 2018/6/21.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool type[4];
const int N=20;

bool isnum(char c)
{
    return '0'<=c&&c<='9';
}

bool issign(char c)
{
    char s[7]={'~','!','@','#','$','%','^'};
    for(int i=0;i<7;i++)if(c==s[i])return true;
    return false;
}

void cnt(char c)
{
    if(isnum(c))type[0]=true;
    if(issign(c))type[1]=true;
    if(isupper(c))type[2]=true;
    if(islower(c))type[3]=true;
}

bool judge(char s[])
{
    int sum=0;
    memset(type,false,sizeof(type));
    for(int i=0;i<N;i++){
        if(strlen(s)<8||strlen(s)>16)return false;
        cnt(s[i]);
    }
    for(int i=0;i<4;i++)if(type[i])sum++;
    if(sum>=3)return true;
    else return false;
}

int main()
{
    int T;
    char s[100];
    cin>>T;
    while(T--){
        memset(s,'\0',sizeof(s));
        cin>>s;
        if(judge(s))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
