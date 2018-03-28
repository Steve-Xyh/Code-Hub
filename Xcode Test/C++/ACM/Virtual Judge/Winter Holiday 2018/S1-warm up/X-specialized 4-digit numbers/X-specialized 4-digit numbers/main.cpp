//
//  main.cpp
//  X-specialized 4-digit numbers
//
//  Created by Steve X on 2017/12/28.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
using namespace std;

int main()
{
    int i,n,sum10,sum12,sum16;
    for(i=2992;i<10000;i++){
        n=i;
        sum10=0;
        while(n){
            sum10+=n%10;
            n/=10;
        }
        n=i;
        sum12=0;
        while(n){
            sum12+=n%12;
            n/=12;
        }
        n=i;
        sum16=0;
        while(n){
            sum16+=n%16;
            n/=16;
        }
        if(sum10==sum12&&sum12==sum16) cout<<i<<endl;
    }
    return 0;
}

