//
//  main.cpp
//  E-score
//
//  Created by Steve X on 2018/3/3.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

string trans(int a)
{
    if(a>100||a<0)return "Score is error!";
    if(a>=90)return "A";
    if(a>=80)return "B";
    if(a>=70)return "C";
    if(a>=60)return "D";
    return "E";
}

int main()
{
    int t;
    while(cin>>t)cout<<trans(t)<<endl;
    return 0;
}
