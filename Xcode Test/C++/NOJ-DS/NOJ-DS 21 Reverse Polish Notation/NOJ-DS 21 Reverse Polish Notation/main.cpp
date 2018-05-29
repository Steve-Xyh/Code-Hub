//  逆波兰表达式(严7.38)
//  main.cpp
//  NOJ-DS 21 Reverse Polish Notation
//
//  Created by Steve X on 2018/5/30.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:栈

#include <iostream>
#include <stack>
#define N 100
using namespace std;

stack<char>opS,tmpS;

bool isOprt(char op)            //判断是否为操作符
{
    return (op=='+')||(op=='-')||(op=='*')||(op=='/')||(op=='(')||(op==')');
}

bool isBracket(char op)         //判断该操作符是否为括号
{
    return (op=='(')||(op==')');
}

int OpLevel(char op)            //返回操作符优先级
{
    switch(op){
        case '+':case '-':return 2;
        case '*':case '/':return 3;
        default :return 1;
    }
}

void judgeBracket(char op)      //处理括号
{
    if(op=='(')opS.push(op);    //如果是左括号’(‘则直接压入opS
    else{                       //如果是右括号’)’则依次弹出opS栈顶的运算符并压入tmpS中直到遇到左括号
        while(opS.top()!='('){
            tmpS.push(opS.top());
            opS.pop();
        }
        opS.pop();              //左括号出栈
    }
}

void judgeOp(char op)                           //处理操作符
{
    if(isBracket(op))judgeBracket(op);          //如果op为括号则处理括号
    if(opS.empty()||opS.top()=='(')opS.push(op);//如果opS为空或栈定为左括号或优先级比栈顶运算符高,则直接压入
    else if(OpLevel(op)>OpLevel(opS.top()))opS.push(op);
    else{                                       //否则将opS栈顶的运算符弹出并压入tmpS中,重新判断opS.top()
        tmpS.push(opS.top());
        opS.pop();
        judgeOp(op);
    }
}

void ReversePolish(char s[])            //转为逆波兰式
{
    char r[N];
    for(int i=0;s[i]!='\0';i++){
        if(isOprt(s[i]))judgeOp(s[i]);  //遇到操作符时处理操作符
        else tmpS.push(s[i]);           //遇到操作数时直接将其压入tmpS
    }
    while(!opS.empty()){                //将opS中剩余的运算符依次弹出并压入tmpS
        tmpS.push(opS.top());
        opS.pop();
    }
    int i=0;
    for(;!tmpS.empty();i++){            //依次弹出tmpS元素保存到r中,将r逆序输出所得的式子即逆波兰式
        r[i]=tmpS.top();
        tmpS.pop();
    }
    for(int j=i-1;j>=0;j--)if(!isBracket(r[j]))cout<<r[j];
    cout<<endl;                         //不输出括号
}

int main()
{
    char s[N];
    cin>>s;
    ReversePolish(s);
    return 0;
}
