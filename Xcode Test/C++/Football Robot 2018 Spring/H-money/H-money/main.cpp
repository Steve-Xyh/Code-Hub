//
//  main.cpp
//  H-money
//
//  Created by Steve X on 2018/3/3.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
using namespace std;

int cnt(int n)
{
    int ans=0;
    if(n>=100){
        ans+=n/100;
        n=n%100;
    }
    if(n>=50){
        ans+=n/50;
        n=n%50;
    }
    if(n>=10){
        ans+=n/10;
        n=n%10;
    }
    if(n>=5){
        ans+=n/5;
        n=n%5;
    }
    if(n>=2){
        ans+=n/2;
        n=n%2;
    }
    ans+=n;
    return ans;
}

int main()
{
    int n,k;
    while(cin>>n&&n!=0){
        int ans=0;
        for(int i=0;i<n;i++){
            cin>>k;
            ans+=cnt(k);
        }
        cout<<ans<<endl;
    }
    return 0;
}
