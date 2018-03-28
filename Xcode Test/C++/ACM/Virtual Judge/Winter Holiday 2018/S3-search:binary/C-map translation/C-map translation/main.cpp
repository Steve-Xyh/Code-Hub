//
//  main.cpp
//  C-map translation
//  https://vjudge.net/contest/205707#problem/C
//  Created by Steve X on 2018/2/24.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:map

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <map>
using namespace std;

map<string,string>a;
char str[50],eng[50],fore[50];

int main()
{
    
    while(gets(str)&&str[0]!='\0'){          //空行结束
        sscanf(str,"%s %s",eng,fore);
        a[fore]=eng;
    }
    while(cin>>fore){
        if(a.count(fore))cout<<a[fore]<<endl;
        else cout<<"eh"<<endl;
    }
    return 0;
}
