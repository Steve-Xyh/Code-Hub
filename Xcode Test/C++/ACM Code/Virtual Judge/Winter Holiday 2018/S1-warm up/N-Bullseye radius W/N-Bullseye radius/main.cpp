//
//  main.cpp
//  N-Bullseye radius W
//
//  Created by Steve X on 2018/2/7.
//  Copyright © 2018年 Steve X. All rights reserved.
//  水题

#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

struct POINT{
    double x,y;
};

struct PLAYER{
    POINT p[3];
};

int ring(POINT p)
{
    double dist=sqrt(p.x*p.x+p.y*p.y);
    if(dist<=3)return 100;
    if(dist<=6)return 80;
    if(dist<=9)return 60;
    if(dist<=12)return 40;
    if(dist<=15)return 20;
    return 0;
}

int calscore(PLAYER a)
{
    return ring(a.p[0])+ring(a.p[1])+ring(a.p[2]);
}

void dispscore(PLAYER x,PLAYER y)
{
    int a=calscore(x),b=calscore(y);
    if(a>b)printf("SCORE: %d to %d, PLAYER 1 WINS.\n",a,b);
    else if(a<b)printf("SCORE: %d to %d, PLAYER 2 WINS.\n",a,b);
    else if(a==b)printf("SCORE: %d to %d, TIE.\n",a,b);
}

int main()
{
    PLAYER a,b;
    double fdata;
    while(cin>>fdata&&fdata!=-100){
        a.p[0].x=fdata;
        cin>>a.p[0].y>>a.p[1].x>>a.p[1].y>>a.p[2].x>>a.p[2].y;
        cin>>b.p[0].x>>b.p[0].y>>b.p[1].x>>b.p[1].y>>b.p[2].x>>b.p[2].y;
        dispscore(a,b);
    }
    return 0;
}
