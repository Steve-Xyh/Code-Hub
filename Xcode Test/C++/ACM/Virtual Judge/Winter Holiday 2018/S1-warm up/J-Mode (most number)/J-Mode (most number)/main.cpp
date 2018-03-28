//
//  main.cpp
//  J-Mode (most number)
//
//  Created by Steve X on 2017/12/28.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#define N 1000000
using namespace std;
int cnt[N];

int main()
{
    int n,x;
    while(scanf("%d",&n)!=EOF){
        for(int i=0;i<N;i++)cnt[i]=0;
        int ans=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            cnt[x]++;
            if(cnt[x]>=(n+1)/2)ans=x;
        }
        cout<<ans<<endl;
    }
    return 0;
}
