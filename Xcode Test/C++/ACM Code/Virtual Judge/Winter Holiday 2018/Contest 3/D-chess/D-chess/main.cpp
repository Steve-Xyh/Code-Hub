//  HDU-6114
//  main.cpp
//  D-chess
//
//  Created by Steve X on 2018/1/20.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:n>m,求C(n,m)%p,若去掉"右边"条件则答案为C(n,m)*A(m,m)%p,拓展;

#include <iostream>
#define N 1000
#define P 1000000007
using namespace std;

long long comb[N+5][N+5];
void getComblist()                 //求组合数表C(n,m)%p
{
    comb[1][0]=comb[1][1]=1%P;
    for(int i=2;i<=N;i++){
        comb[i][0]=1;
        for(int j=1;j<=i;j++){
            comb[i][j]=(comb[i-1][j]+comb[i-1][j-1])%P;
        }
    }
}


int main()
{
    int T,m,n,a,b;
    getComblist();
    cin>>T;
    while(T--){
        cin>>n>>m;
        a=m>n?m:n;
        b=m<n?m:n;
        cout<<comb[a][b]<<endl;
    }
    return 0;
}
