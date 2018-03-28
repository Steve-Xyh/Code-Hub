//
//  main.cpp
//  B-The Balance POJ2142
//
//  Created by Steve X on 2017/12/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//
//思路:高中数学线性规划,求整数点

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int a,b,d,na,nb,ma,mb,X,Y;
    while(cin>>a>>b>>d&&d>0){
        if(a>b){
            if(d%a==0){
                X=d/a;
                Y=0;
            }
            else{
                int tX=X=d/a;
                while((d-a*X)%b!=0)X--;                      //X向左搜索整数解
                Y=(d-a*X)/b;
                while((d-a*tX)%b!=0)tX++;                    //tX向右搜索整数解
                int tY=(d-a*tX)/b;
                na=abs(X)+abs(Y);ma=a*abs(X)+b*abs(Y);
                nb=abs(tX)+abs(tY);mb=a*abs(tX)+b*abs(tY);
                if(na>nb||(na==nb&&ma>mb)){
                    X=tX;Y=tY;                               //输出n最少,n相同则输出m最少
                }
            }
        }
        else{
            if(d%b==0){
                Y=d/b;
                X=0;
            }
            else{
                int tY=Y=d/b;
                while((d-b*Y)%a!=0)Y--;
                X=(d-b*Y)/a;
                while((d-b*tY)%a!=0)tY++;
                int tX=(d-b*tY)/a;
                na=abs(X)+abs(Y);ma=a*abs(X)+b*abs(Y);
                nb=abs(tX)+abs(tY);mb=a*abs(tX)+b*abs(tY);
                if(na>nb||(na==nb&&ma>mb)){
                    X=tX;Y=tY;
                }
            }
        }
        cout<<abs(X)<<" "<<abs(Y)<<endl;
    }
    return 0;
}
