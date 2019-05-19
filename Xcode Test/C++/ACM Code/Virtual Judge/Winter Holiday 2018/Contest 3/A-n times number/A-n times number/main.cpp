//  HDU-6108
//  main.cpp
//  A-n times number
//
//  Created by Steve X on 2018/1/20.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:满足(p-1)%b==0的数则p进制下b各位之和==x,b是x的倍数

#include <iostream>
using namespace std;

int cntfactor(int n)          //计算因子个数
{
    int cnt=0;
    for(int i=1;i<=n/i;i++){
        if(n%i==0){
            if(i*i!=n)cnt+=2;
            else cnt++;
        }
    }
    return cnt;
}

int main()
{
    int T,p;
    cin>>T;
    while(T--){
        cin>>p;
        cout<<cntfactor(p-1)<<endl;
    }
    return 0;
}
