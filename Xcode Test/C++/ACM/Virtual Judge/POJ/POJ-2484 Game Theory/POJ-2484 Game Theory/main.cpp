//
//  main.cpp
//  POJ-2484 Game Theory
//
//  Created by Steve X on 2018/2/8.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:博弈论,n=1,2时先取必胜,n>=3先取必败

#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin>>n&&n!=0){
        if(n<3)cout<<"Alice"<<endl;
        else cout<<"Bob"<<endl;
    }
    return 0;
}
