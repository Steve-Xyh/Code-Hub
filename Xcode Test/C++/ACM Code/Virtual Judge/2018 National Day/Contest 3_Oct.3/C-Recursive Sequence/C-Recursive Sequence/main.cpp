//  ##AC##  ##矩阵快速幂##   ##Fast Matrix Power##
//  main.cpp
//  C-Recursive Sequence
//  https://vjudge.net/contest/256714#problem/C
//  Created by Steve X on 2018/10/3.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:Fast Matrix Power

#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
const ll mod=2147493647;

struct Mat {
    int row,col;
    ll a[7][7]={{1,2,1},{1},{0,0,1,4,6,4,1},{0,0,0,1,3,3,1},{0,0,0,0,1,2,1},{0,0,0,0,0,1,1,},{0,0,0,0,0,0,1}};
    
    void init(int x){
        row=col=7;
        for(int i=0;i<row;i++)
            for(int j=0;j<col;j++)a[i][j]=x;
    }
    
    void initEye(int m,int n,ll x){
        init(0);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)if(i==j)a[i][j]=x;
    }
    
    void initcol(ll x[],int n){
        init(0);
        for(int i=0;i<n;i++)a[i][0]=x[i];
    }
}A;

Mat multi(Mat a,Mat b)
{
    Mat ans;
    ans.row=ans.col=7;
    for(int i=0;i<ans.row;i++){
        for(int j=0;j<ans.col;j++){
            ans.a[i][j]=0;
            for(int p=0;p<ans.col;p++)ans.a[i][j]+=(a.a[i][p]*b.a[p][j])%mod;
            ans.a[i][j]%=mod;
        }
    }
    return ans;
}

Mat pow_mod(Mat A,ll x)
{
    Mat tmp=A,ans;
    ans.initEye(7,7,1);
    while(x>=1){
        if(x&1)ans=multi(ans,tmp);
        tmp=multi(tmp,tmp);
        x>>=1;
    }
    return ans;
}

ll solve(ll n,ll a,ll b)
{
    ll x[7]={0,0,81,27,9,3,1};
    x[0]=b;
    x[1]=a;
    
    Mat ans,tmp;
    tmp=pow_mod(A,n-2);
    ans.initcol(x,7);
    ans=multi(tmp,ans);
    
    return ans.a[0][0];
}

int main()
{
    ll T,n,a,b;
    cin>>T;
    while(T--){
        scanf("%lld%lld%lld",&n,&a,&b);
        printf("%lld\n",solve(n,a,b));
    }
    return 0;
}
