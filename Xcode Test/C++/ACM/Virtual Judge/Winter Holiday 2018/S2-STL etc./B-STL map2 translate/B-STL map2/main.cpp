//
//  main.cpp
//  B-STL map2
//  https://vjudge.net/contest/205706#problem/B
//  Created by Steve X on 2018/2/21.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:map

#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <cctype>
#define N 3010
using namespace std;

char c[N];
string inp,outp,tag;
map<string,string>a;

void creatmap()                          //创建map映射,即词典
{
    while(cin>>outp&&outp!="END"){
        cin>>inp;
        a[inp]=outp;                     //规定翻译内容
    }
}

void translate()
{
    int len=(int)strlen(c);
    inp="";
    for(int i=0;i<len;i++){
        if(islower(c[i]))inp+=c[i];      //如果该字符是小写字母则添加到输入内容中
        else{
            if(a.count(inp))cout<<a[inp];//如果词典中含有此单词则翻译,否则原样输出
            else cout<<inp;
            inp="";                      //清空输入内容,并输出此非小写字母字符
            cout<<c[i];
        }
    }
    cout<<endl;                          //翻译完一句话换行
}

int main()
{
    cin>>tag;
    if(tag=="START")creatmap();
    cin>>tag;
    getchar();                           //存储START后的换行符
    if(tag=="START")while(gets(c)&&strcmp(c,"END")!=0)translate();
    return 0;
}
