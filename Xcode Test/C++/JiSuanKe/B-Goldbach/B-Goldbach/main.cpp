//
//  main.cpp
//  B-Goldbach
//  https://www.jisuanke.com/contest/1227/68937
//  Created by Steve X on 2018/4/22.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstring>
#define N 10000010
#define maxn 1000000
using namespace std;

//Euler筛法(欧氏筛)
bool isprime[N+10];
long long primenum[maxn+10],cnt;
void Euler()
{
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    for(long long i=2;i<=N;i++){
        if(isprime[i])primenum[++cnt]=i;
        for(int j=1;j<=cnt&&i*primenum[j]<=N;j++){
            isprime[i*primenum[j]]=false;
            if(i%primenum[j]==0)break;
        }
    }
}

//Miller-Rabin素性判断
long long Witness(long long A,long long i,long long n)
{
    long long X,Y;
    if(i == 0)return 1;
    X = Witness(A, i/2, N);
    if(X == 0)return 0;
    Y=(X*X)%N;
    if(Y==1&&X!=1&&X!=N-1)return 0;
    if(i%2!=0)Y=(A*Y)%N;
    return Y;
}

bool IsPrime(long long n)
{
    return Witness(rand()%(n-2)+2,n-1,n)==1;
}

void solve(long long n)
{
    for(int i=1;i<=cnt;i++){
        if(IsPrime(n-primenum[i])){
            cout<<primenum[i]<<" "<<n-primenum[i]<<endl;
            break;
        }
    }
}

int main()
{
    int T;
    long long n;
    Euler();
    cin>>T;
    while(T--){
        cin>>n;
        solve(n);
    }
    return 0;
}
