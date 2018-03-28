//
//  main.cpp
//  D-kinetic energy W
//  https://vjudge.net/contest/205706#problem/D
//  Created by Steve X on 2018/2/21.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:动能定理

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double g=9.81;                  //重力加速度g
    double k,l,h,m,Eg,Ep,Ek,v;      //弹性系数,绳长,高度,质量,重力势能,弹性势能,动能,末速度
    while(cin>>k>>l>>h>>m&&!(k==0&&l==0&&h==0&&m==0)){
        Eg=m*g*h;
        Ep=h>l?0.5*k*(h-l)*(h-l):0;
        Ek=Eg-Ep;
        if(Ek>=0){
            v=sqrt(2.0*Ek/m);
            if(v>10.0)cout<<"Killed by the impact."<<endl;
            else cout<<"James Bond survives."<<endl;
        }
        else cout<<"Stuck in the air."<<endl;
    }
    return 0;
}
