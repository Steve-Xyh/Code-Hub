//  HDU-2057
//  main.cpp
//  A-hex calculation
//  https://vjudge.net/contest/212920#problem/A
//  Created by Steve X on 2018/2/19.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
char a[15],b[15];

int hex(char c)                       //字母转16进制数字
{
    if(isalnum(c)){
        if(isalpha(c))return c-'A'+10;
        return c-'0';
    }
    return 0;
}

long long power(int a,int r)          //乘幂
{
    long long ans=1;
    while(r--)ans*=a;
    return ans;
}

long long hexcal(char a[])            //字符串转16进制数
{
    int len=0;
    long long x=0;
    for(int i=0;a[i]!='\0';i++)len++;
    for(int i=len-1;i>=0;i--){
        if(isalnum(a[i]))x+=hex(a[i])*power(16,len-i-1);
        else if(a[i]=='+')continue;
        else if(a[i]=='-')x*=-1;
    }
    return x;
}

int main()
{
    while(cin>>a>>b){
        long long sum=hexcal(a)+hexcal(b);
        if(sum>=0)printf("%llX\n",sum);
        else printf("-%llX\n",-1*sum);//防止输出补码,取绝对值输出负号
        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
    }
    return 0;
}
