//  HDU-4841
//  main.cpp
//  D-round table
//
//  Created by Steve X on 2018/1/24.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:循环,模m运算

#include <iostream>
#include <cstdio>
#include <cstring>
#define N 32768*2
using namespace std;
int A[N];

int main()
{
    int n,m,cnt;
    while(~scanf("%d%d",&n,&m)){
        
        memset(A,0,sizeof(A));      //初始值均为0,将坏人设为1
        cnt=0;
        
        int i=1;
        while(cnt<n){
            for(int j=0;j<m;){
                while(A[i]){        //排除死人
                    i=(i+1)%(2*n);
                    if(i==0)i=2*n;
                }
                
                if(A[i]==0){        //数m个活人
                    j++;
                    i=(i+1)%(2*n);
                    if(i==0)i=2*n;
                }
            }
            i=(i-1)%(2*n);          //数完m个活人,将i归位
            if(i==0)i=2*n;
            
            A[i]=1;                 //将坏人设为1
            cnt++;                  //处死n个坏人
        }
        
        for(int i=1;i<=2*n;i++){    //根据01值输出GB
            if(A[i])cout<<"B";
            if(A[i]==0)cout<<"G";
            if(i%50==0)cout<<endl;  //每50个字母换一次行
        }
        if(2*n%50)cout<<endl;       //如果刚好50个字母则不再换行
        cout<<endl;                 //每组数据之间空一行
    }
    return 0;
}
