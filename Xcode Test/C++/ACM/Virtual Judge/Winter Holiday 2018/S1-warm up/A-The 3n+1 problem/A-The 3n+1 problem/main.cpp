//
//  main.cpp
//  A-The 3n+1 problem
//
//  Created by Steve X on 2017/12/28.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
using namespace std;

int algo(int n)
{
    int sum=1;
    while(n>1){
        if(n%2!=0)n=3*n+1;
        else n/=2;
        sum++;
    }
    return sum;
}

int max(int a,int b)
{
    return a>=b?a:b;
}

int main()
{
    int i,j,a,b;
    while(scanf("%d%d",&i,&j)!=EOF){
        int ans=0;
        a=i<=j?i:j;
        b=i>=j?i:j;
        for(int p=b;p>=a;p--){
            //if(j>=1000&&p<=j-j/10)break;
            ans=max(ans,algo(p));
        }
        cout<<i<<" "<<j<<" "<<ans<<endl;
    }
    return 0;
}
