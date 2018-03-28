//
//  main.cpp
//  D-3*2^(n-1)
//
//  Created by Steve X on 2017/12/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#define maxn 50
using namespace std;

long long RPG(int n)
{
    long long f[maxn];
    f[1]=3;
    f[2]=6;
    f[3]=6;
    
    for(int i=4;i<=n;i++){
        f[i]=f[i-1]+2*f[i-2];
    }
    return f[n];
}

int main()
{
    int N;
    while(scanf("%d",&N)!=EOF){
        cout<<RPG(N)<<endl;
    }
    return 0;
}
