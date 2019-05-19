//  ##Binary Search##   ##lower_bound## ##TLE,huge IO##
//  main.cpp
//  Gym-101964E Fishermen
//  https://vjudge.net/problem/Gym-101964E
//  Created by Steve X on 2018/11/17.
//  Copyright © 2018 Steve X. All rights reserved.
//  Methods:二分,前缀数组https://mp.weixin.qq.com/s/epeNJ4Wj-OtTt6bx6CsL1A

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=2e5+10;
int n,m,l,ans[N],sum[N];

struct fish{
    int x,y;                                        //Coordinate of fish
}f[N];

struct man{
    int x,num;                                      //x Axis,original number
    bool operator <(const man &m)const{
        return x<m.x;
    }
}a[N];

void solve()
{
    sort(a,a+n);
    
    for(int i=0;i<m;i++){
        if(l<f[i].y)continue;                       //The line is not long enough
        man tmp;
        tmp.x=f[i].x-(l-f[i].y);
        int left=(int)(lower_bound(a,a+n,tmp)-a);   //Left bound of fishermen
        tmp.x=f[i].x+(l-f[i].y);
        int right=(int)(upper_bound(a,a+n,tmp)-a);  //Right bound of fishermen
        
        sum[left]++;                                //Start of range
        sum[right]--;                               //End of range
    }
    
    for(int i=0;i<n;i++){
        sum[i]+=sum[i-1];                           //Add the current sum and previous sum
        ans[a[i].num]=sum[i];                       //Link current sum to the original number
    }
    
    for(int i=0;i<n;i++)printf("%d\n",ans[i]);
}

int main()
{
    while(~scanf("%d%d%d",&m,&n,&l)){
        memset(sum,0,sizeof(sum));
        memset(ans,0,sizeof(ans));
        for(int i=0;i<m;i++)scanf("%d%d",&f[i].x,&f[i].y);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i].x);
            a[i].num=i;                             //Mark the original number
        }
        solve();
    }
    return 0;
}
