//  CHD-ACM
//  main.cpp
//  A-Unpredictable Accidents
//  https://www.nowcoder.com/acm/contest/102/A
//  Created by Steve X on 2018/4/14.
//  Copyright © 2018年 Steve X. All rights reserved.
//

#include <iostream>
using namespace std;

void CalTime(int x)
{
    int h=12,m=0;
    m+=x%60;
    h+=x/60;
    cout<<h<<":";
    if(m<10)cout<<0;
    cout<<m<<endl;
}

int main()
{
    int T,x;
    cin>>T;
    while(T--){
        cin>>x;
        CalTime(x);
    }
    return 0;
}
