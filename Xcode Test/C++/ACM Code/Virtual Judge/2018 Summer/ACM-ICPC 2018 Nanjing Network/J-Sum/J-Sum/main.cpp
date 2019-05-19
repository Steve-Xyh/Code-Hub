//  ACM-ICPC 2018 南京赛区网络预赛
//  main.cpp
//  J-Sum
//  https://www.jisuanke.com/contest/1555/100464
//  Created by Steve X on 2018/9/1.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

const int N=2e6+10;
const int maxn=2e7+10;

int p[N],a[N],cnt,sqsum,sqfree[N];
void getFactor(int n)
{
    int now=n;
    for(int i=2;i<=n/i;i++){
        if(now%i==0){
            p[++cnt]=i;
            a[cnt]=0;
            while(now%i==0){
                a[cnt]++;
                now/=i;
            }
        }
    }
    if(now!=1){
        p[++cnt]=now;
        a[cnt]=1;
    }
}

void init()
{
    for(int i=0;i<maxn;i++){
        memset(p,0,sizeof(p));
        memset(a,0,sizeof(a));
        cnt=0;
        getFactor(i);
        bool tag=true;
        for(int j=1;j<=cnt;j++)if(a[j]!=1)tag=false;
        if(tag){
            sqfree[sqsum++]=i;
            cout<<sqsum<<"#: "<<i<<endl;
        }
    }
}

int main()
{
    init();
    cout<<"initialized"<<endl;
    cout<<"successifully"<<endl;
    return 0;
}
