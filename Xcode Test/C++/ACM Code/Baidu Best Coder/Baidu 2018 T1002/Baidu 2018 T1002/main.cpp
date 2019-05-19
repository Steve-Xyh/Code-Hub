//  百度之星2018资格赛 T1002 子串查询
//  main.cpp
//  Baidu 2018 T1002
//  http://bestcoder.hdu.edu.cn/contests/contest_showproblem.php?cid=820&pid=1002
//  Created by Steve X on 2018/8/5.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:前缀和

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N=1e5+10;
int len[N][30];                 //len[i][j]表示字母表第j位字母在字符串A[1,i]出现的次数
char s[N];                      //字符串s,从0开始

void init(int n)
{
    memset(len,0,sizeof(len));
    for(int i=1;i<=n;i++){
        for(int j=0;j<26;j++)len[i][j]=len[i-1][j];
        len[i][s[i-1]-'A']++;
    }
}

void query(int l,int r)         //A[l,r]出现次数=A[r]-A[l-1]
{
    for(int j=0;j<26;j++){
        if(len[r][j]-len[l-1][j]){
            printf("%d\n",len[r][j]-len[l-1][j]);
            break;
        }
    }
}

int main()
{
    int T,n,q,l,r,cnt=1;
    cin>>T;
    while(T--){
        printf("Case #%d:\n",cnt++);
        cin>>n>>q;
        cin>>s;
        init(n);
        for(int i=0;i<q;i++){
            scanf("%d%d",&l,&r);
            query(l,r);
        }
    }
    return 0;
}
