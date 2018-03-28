//
//  main.c
//  NOJ80-long number addition
//
//  Created by Steve X on 2017/11/16.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void plus(int A[],int B[],int a,int b)           //正数加法
{
    int C[100],t=0;
    for(int i=0;i<100;i++){
        C[i]=0;
    }
    
    for(int i=99;i>=0;i--){
        C[i]+=A[i]+B[i];
        if(C[i]>9){
            C[i-1]+=C[i]/10;
            C[i]%=10;
        }
    }
    for(t=0;C[t]==0;t++);
    for(int i=t;i<100;i++){
        printf("%d",C[i]);
    }
    printf("\n");
}

void PositiveMinus(int A[],int B[],int a,int b) //大数减小数
{
    int C[100],t=0;
    for(int i=0;i<100;i++){
        C[i]=0;
    }
    
    for(int i=99;i>=a;i--){
        C[i]=C[i]+A[i]-B[i];
        if(C[i]<0){
            C[i-1]--;
            C[i]=10+C[i];
        }
    }
    for(t=0;C[t]==0;t++);
    for(int i=t;i<100;i++){
        printf("%d",C[i]);
    }
    printf("\n");
}

int main(){
    int A[100],B[100],a,b,x,y,cnt=0,cnta=0,cntb=0;  //输入A,B
    char str1[100],str2[100];
    for(int i=0;i<100;i++){
        A[i]=0;
        B[i]=0;
    }
    
    gets(str1);
    gets(str2);
    for(x=0;str1[x]!='\0';x++);
    for(y=0;str2[y]!='\0';y++);
    x--;
    y--;
    for(a=99;x>=0;a--){
        if(str1[x]!='-')A[a]=str1[x]-'0';
        else{
            cnta++;
            break;
        }
        x--;
    }
    for(b=99;y>=0;b--){
        if(str2[y]!='-')B[b]=str2[y]-'0';
        else{
            cntb++;
            break;
        }
        y--;
    }
    a++;
    b++;
    cnt=cnta+cntb;
    
    if(cnt==0)plus(A,B,a,b);                       //分类讨论 1.正数加法 2.负数加法 3.大数减小数 4.小数减大数
    else if(cnt==2){
        printf("-");
        plus(A,B,a,b);
    }
    else if(cnt==1){
        if(cnta==0){
            if(a<b)PositiveMinus(A,B,a,b);
            if(a>b){
                printf("-");
                PositiveMinus(B,A,b,a);
            }
            if(a==b){
                int i;
                for(i=a;i<100;i++){
                    if(A[i]>B[i]){
                        PositiveMinus(A,B,a,b);
                        break;
                    }
                    if(A[i]<B[i]){
                        printf("-");
                        PositiveMinus(B,A,b,a);
                        break;
                    }
                }
                if(i==100)printf("0\n");
            }
        }
        if(cntb==0){
            if(a>b)PositiveMinus(B,A,b,a);
            if(a<b){
                printf("-");
                PositiveMinus(A,B,a,b);
            }
            if(a==b){
                int i;
                for(i=a;i<100;i++){
                    if(A[i]<B[i]){
                        PositiveMinus(B,A,b,a);
                        break;
                    }
                    if(A[i]>B[i]){
                        printf("-");
                        PositiveMinus(A,B,a,b);
                        break;
                    }
                }
                if(i==100)printf("0\n");
            }
        }
    }
    return 0;
}
