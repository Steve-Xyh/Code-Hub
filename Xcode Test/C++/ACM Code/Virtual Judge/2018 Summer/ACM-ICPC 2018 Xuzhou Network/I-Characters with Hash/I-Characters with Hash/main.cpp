//
//  main.cpp
//  I-Characters with Hash
//
//  Created by Steve X on 2018/9/9.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <cmath>
//#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T,n;
    char z;
    string s;
    cin>>T;
    while(T--){
        cin>>n>>z;
        cin>>s;
        int ans=n<<1,cnt=0;
        for(int i=0;i<n;i++){
            if(abs(z-s[i])==0)cnt++;
            else break;
        }
        if(abs(z-s[0])==0)ans-=2*cnt;
        else if(abs(z-s[0])<10)ans-=1;
        cout<<ans<<endl;
    }
    return 0;
}
