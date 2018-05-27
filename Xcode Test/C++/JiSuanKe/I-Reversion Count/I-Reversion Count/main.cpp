//
//  main.cpp
//  I-Reversion Count
//  https://www.jisuanke.com/contest/1227/69719
//  Created by Steve X on 2018/4/22.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstring>
#define N 100
using namespace std;

void Minus(char a[],char b[],int c[],int n,int &tag)
{
    memset(c,0,sizeof(int)*n);
    for(int i=n-1;i>=0;i--){
        c[i]=c[i]+(a[i]-'0')-(b[i]-'0');
        if(i&&c[i]<0){
            c[i-1]--;
            c[i]=10+c[i];
        }
        if(c[i]<0)tag=1;
    }
}

void Division(int c[],int a,int n)
{                            //大数除以小数
    int r=0;
    for(int i=0;i<n;i++){
        c[i]+=r*10;
        r=c[i]%a;
        c[i]/=a;
    }
}

bool Judge(char a[],int c[],int n)
{
    char b[N];
    int tag=0,p=0;
    for(int i=n-1;i>=0;i--)b[n-1-i]=a[i];
    if(a[0]>=b[0])Minus(a,b,c,n,tag);
    else if(a[0]<b[0])Minus(b,a,c,n,tag);
    else if(tag)Minus(b,a,c,n,tag);
    Division(c,9,n);
    while(c[p++]==0);
    if(n-p<=1)return true;
    for(int i=p+1;i<n;i++)if(c[i]!=c[i-1])return false;
    return true;
}

int main()
{
    char a[N];
    int c[N];
    while(cin>>a){
        int n=0;
        while(a[n++]!='\0');n--;
        if(Judge(a,c,n))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
