//  [NWPU2018]组队训练赛第五场
//  main.cpp
//  I-Little Boxes
//  https://vjudge.net/contest/249506#problem/I
//  Created by Steve X on 2018/8/30.
//  Copyright © 2018年 Steve X. All rights reserved.
//  Methods:W

//#define TEST
#include <iostream>
using namespace std;

int main()
{
    int T;
    unsigned long long a,b,c,d,sum;
    
#ifdef TEST
    unsigned long long t=-1;            //t=2^63-1,cout<<2^64
    cout<<"ull "<<t<<endl;
#endif
    
    cin>>T;
    while(T--){
        cin>>a>>b>>c>>d;
        sum=a+b+c+d;
        if(a>0||b>0||c>0||d>0){
            if(sum)cout<<sum<<endl;
            else cout<<"18446744073709551616"<<endl;
        }
        else cout<<sum<<endl;
    }
    return 0;
}
