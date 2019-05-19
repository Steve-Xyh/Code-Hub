//  ##DNF##
//  main.cpp
//  G-Trace
//
//  Created by Steve X on 2018/9/9.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

const long long N=5e5+10;

struct line{
    long long len,num,ori;
}x[N],y[N];

bool cmp(line a,line b)
{
    return a.len!=b.len?a.len>b.len:a.num>b.num;
}

int main()
{
    long long n;
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>x[i].len>>y[i].len;
        x[i].num=y[i].num=i;
        x[i].ori=x[i].len;
        y[i].ori=y[i].len;
    }
    long long px=x[n-1].len;
    long long py=y[n-1].len;
    sort(x,x+n,cmp);
    sort(y,y+n,cmp);
    if(n>1){
        x[0].len-=x[1].len;
        y[0].len-=y[1].len;
        if(x[1].num!=n-1)for(long long i=0;i<n-1;i++)if(x[i].len>=px)x[i].len=x[i].ori-px;
        if(y[1].num!=n-1)for(long long i=0;i<n-1;i++)if(y[i].len>=py)y[i].len=y[i].ori-py;
    }
    long long ans=0;
    for(long long i=0;i<n;i++)ans+=x[i].len+y[i].len;
    cout<<ans<<endl;
    return 0;
}
