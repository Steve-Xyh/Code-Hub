//
//  main.cpp
//  A-binary number
//
//  Created by Steve X on 2018/2/24.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#define N 1000000
using namespace std;

void binarylist(long long b[])             //b[i]为i的二进制形式
{
    b[0]=0;
    b[1]=1;
    for(int i=2;i<N;i++)b[i]=10*b[i/2]+i%2;
}

int main()
{
    int n;
    long long ans=0,b[N];
    binarylist(b);
    while(cin>>n&&n){
        for(int i=1;;i++){
            if(b[i]%n==0){
                ans=b[i];
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
