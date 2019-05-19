//  51Nod-1069  ##博弈论##
//  main.cpp
//  B-Nim Game
//  https://vjudge.net/contest/243682#problem/B
//  Created by Steve X on 2018/8/8.
//  Copyright © 2018年 Steve X. All rights reserved.
//  思路:可制造两堆相等者必胜,面对两堆相等者必败

#include <iostream>
using namespace std;

int main()
{
    //可制造两堆相等者必胜,面对两堆相等者必败
    //若相等的堆数成对出现,则A必败,否则A必胜
    //a^b^b=a,则有0^x^x=0,a表示A除最后一轮以外面对的情况即a=a1^a2^a3^...^an-2
    //若a==0,则a^b^b==0,A面对两堆相等情况,A必败,反之a!=0,则a^b^b!=0,A必胜
    int n;
    while(cin>>n){
        int a,ans=0;
        cin>>ans;
        for(int i=1;i<n;i++){
            cin>>a;
            ans^=a;
        }
        if(ans)cout<<"A"<<endl;
        else cout<<"B"<<endl;
    }
    return 0;
}
