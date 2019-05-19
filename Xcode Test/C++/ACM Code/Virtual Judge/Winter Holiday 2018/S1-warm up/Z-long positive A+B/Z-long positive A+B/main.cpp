//
//  main.cpp
//  Z-long positive A+B
//
//  Created by Steve X on 2017/12/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <stdio.h>
#define N 1010
using namespace std;

int A[N],B[N],C[N];

void Plus(int A[],int B[])           //正数加法
{
    int t=0;
    memset(C,0,sizeof(C));
    
    for(int i=N-1;i>=0;i--){
        C[i]+=A[i]+B[i];
        if(C[i]>9){
            C[i-1]+=C[i]/10;
            C[i]%=10;
        }
    }
    for(t=0;C[t]==0;t++);
    for(int i=t;i<N;i++){
        printf("%d",C[i]);
    }
    cout<<endl;
}

/*void setm(int A[],int n)
{
    for(int i=10;i<N;i++)A[i]=n;
}*/

int main(){
    int T,a,b,x,y;  //输入A,B
    char str1[N],str2[N];
    
    cin>>T;
    for(int i=1;i<=T;i++){
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        memset(str1,0,sizeof(str1));
        memset(str2,0,sizeof(str2));
        cin>>str1;
        cin>>str2;
        //setm(A,9);setm(B,9);
        for(x=0;str1[x]!='\0';x++);
        for(y=0;str2[y]!='\0';y++);
        x--;
        y--;
        for(a=N-1;x>=0;a--){
            A[a]=str1[x]-'0';
            x--;
        }
        for(b=N-1;y>=0;b--){
            B[b]=str2[y]-'0';
            y--;
        }
        if(i!=1)cout<<endl;
        cout<<"Case "<<i<<":\n"<<str1<<" + "<<str2<<" = ";;
        Plus(A,B);
    }
    return 0;
}
