//
//  main.cpp
//  CodeForces-914B Conan game
//  https://vjudge.net/contest/209734#problem/A
//  Created by Steve X on 2018/2/12.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:先者选取出现奇数次的最大数即可获胜,则所有数出现偶数次时先者必败

#include <iostream>
#include <cstring>
#define N 100000+10
using namespace std;
int cnt[N];

int main()
{
    int n,x;
    while(cin>>n){
        int tag=0;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            cin>>x;
            cnt[x]++;
        }
        for(int i=0;i<N;i++){
            if(cnt[i]%2){
                tag=1;
                break;
            }
        }
        if(tag)cout<<"Conan"<<endl;
        else cout<<"Agasa"<<endl;
    }
    return 0;
}
