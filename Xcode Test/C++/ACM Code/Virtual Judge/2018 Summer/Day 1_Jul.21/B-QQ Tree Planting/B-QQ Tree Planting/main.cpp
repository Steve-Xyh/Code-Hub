//  Day 1 HDU-4503
//  main.cpp
//  B-QQ Tree Planting
//  https://vjudge.net/contest/239961#problem/B
//  Created by Steve X on 2018/7/23.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:共C(n,3)种情况,计算反面情况
//  #define TEST
#include <iostream>
#include <cstdio>
using namespace std;

const int N=1010;

int main()
{
    int T,n,b[N];
    cin>>T;
    while(T--){
        cin>>n;
        int sum=0,cnt=n*(n-1)*(n-2)/6;  //计算组合数C(n,3)种情况
        for(int i=0;i<n;i++){
            cin>>b[i];
            sum+=b[i]*(n-b[i]-1);       //关系不同即两人是朋友,另一个不是朋友,总数为b*(n-b-1)
        }
        sum=cnt-sum/2;                  //计算反面,取反,去除重复sum/2
        double ans=1.0*sum/cnt;
#ifdef TEST
        cout<<"sum:"<<sum<<endl;
        cout<<"cnt:"<<cnt<<endl;
#endif
        printf("%.3f\n",ans);
    }
    return 0;
}
