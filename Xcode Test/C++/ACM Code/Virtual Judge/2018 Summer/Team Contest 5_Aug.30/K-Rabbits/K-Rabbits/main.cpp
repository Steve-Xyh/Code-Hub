//  [NWPU2018]组队训练赛第五场
//  main.cpp
//  K-Rabbits
//  https://vjudge.net/contest/249506#problem/K
//  Created by Steve X on 2018/8/30.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:求相邻两点间距离和,减去两端距离较小者

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=510;
int a[N];

int main()
{
    int T,n;
    cin>>T;
    while(T--){
        cin>>n;
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i)ans+=a[i]-a[i-1]-1;            //空位距离和
        }
        ans-=min(a[1]-a[0]-1,a[n-1]-a[n-2]-1);  //去掉两端空位较小者
        cout<<ans<<endl;
    }
    return 0;
}
