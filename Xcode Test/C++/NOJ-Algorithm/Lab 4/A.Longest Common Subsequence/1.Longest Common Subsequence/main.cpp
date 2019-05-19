//  POJ-1458 最长公共子序列
//  main.cpp
//  1.Longest Common Subsequence
//  https://vjudge.net/contest/202547#problem/D
//  Created by Steve X on 2018/10/25.
//  Copyright © 2018 Steve X. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int N=1010;
int dp[N][N];               //dp[i][j]表示A串前i个字符和B串前j个字符的LCS(最长公共子序列)

int LCS(string a,string b)
{
    int la=(int)a.size(),lb=(int)b.size();
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=la;i++){
        for(int j=1;j<=lb;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(a[i-1]==b[j-1])dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
        }
    }
    return dp[la][lb];
}

int main()
{
    string a,b;
    while(cin>>a>>b){
        cout<<LCS(a,b)<<endl;
    }
    return 0;
}
