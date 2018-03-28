//
//  main.cpp
//  M-digital root
//
//  Created by Steve X on 2017/12/28.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <iostream>
#include <cstring>
#define N 1000
using namespace std;
char str[N];
int A[N];

void str2num(char str[],int A[],int n)
{
    for(int i=0;i<n;i++){
        if(str[i]=='\0')break;
        A[i]=str[i]-'0';
    }
}

int droot(int A[],int n)
{
    int ans=0,temp=0;
    for(int i=0;i<n;i++)temp+=A[i];
    while(temp>0){
        ans+=temp%10;
        temp/=10;
    }
    if(ans>9){
        temp=ans;ans=0;
        while(temp>0){
            ans+=temp%10;
            temp/=10;
        }
        if(ans>9){
            temp=ans;ans=0;
            while(temp>0){
                ans+=temp%10;
                temp/=10;
            }
        }
    }
    return ans;
}

int main()
{
    while (1){
        memset(str,0,sizeof(str));
        memset(A,0,sizeof(A));
        cin>>str;
        if(str[0]=='0')break;
        str2num(str,A,N);
        cout<<droot(A,N)<<endl;
    }
    return 0;
}
