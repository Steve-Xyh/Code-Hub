//
//  main.cpp
//  A-romantic HDU-2669
//
//  Created by Steve X on 2017/12/26.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
using namespace std;

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int ex_gcd(int a,int b,int &x,int &y)
{
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    else{
        int r=ex_gcd(b,a%b,y,x);
        y-=x*(a/b);
        return r;
    }
}

int main()
{
    int a,b,x,y,X,Y,g,t;
    while(scanf("%d%d",&a,&b)!=EOF){
        x=y=t=0;
        g=gcd(a,b);
        if(g!=1)cout<<"sorry\n";
        else {
            ex_gcd(a,b,x,y);
            X=x+b*t;
            Y=y-a*t;
            if(X>0){
                while(X>0){
                    if(x+b*(t-1)<0)break;
                    t--;
                    X=x+b*t;
                    Y=y-a*t;
                }
            }
            else if(X<0){
                while(X<0){
                    t++;
                    X=x+b*t;
                    Y=y-a*t;
                }
            }
            if(X<0)cout<<"sorry\n";
            else cout<<X<<" "<<Y<<endl;
        }
    }
    return 0;
}
