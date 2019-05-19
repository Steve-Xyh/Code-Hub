//
//  main.cpp
//  E-A+B W
//
//  Created by Steve X on 2017/12/28.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;
string s[10]={{"zero"},{"one"},{"two"},{"three"},{"four"},{"five"},{"six"},{"seven"},{"eight"},{"nine"}};

int cal(string str[])
{
    int ans,a=0,b=0,c=0,d=0,A=0,B=0,t;
    for(int i=0;i<10;i++){
        int cnt=0;
        if(str[0]==s[i]){
            A=a=i;
            for(int j=0;j<10;j++){
                if(str[1]==s[j]){
                    b=j;
                    cnt++;
                    break;
                }
            }
            if(cnt){
                A=10*a+b;
                break;
            }
        }
    }
    for(t=0;str[t]!="+";t++);
    t++;
    for(int i=0;i<10;i++){
        int cnt=0;
        if(str[t]==s[i]){
            B=c=i;
            for(int j=0;j<10;j++){
                if(str[t+1]==s[j]){
                    d=j;
                    cnt++;
                    break;
                }
            }
            if(cnt){
                B=10*c+d;
                break;
            }
        }
    }
    ans=A+B;
    return ans;
}

int main()
{
    string str[6];
    while(1){
        for(int i=0;i<6;i++){
            cin>>str[i];
            if(str[i]=="=")break;
        }
        if(cal(str)==0)break;
        cout<<cal(str)<<endl;
    }
    return 0;
}
