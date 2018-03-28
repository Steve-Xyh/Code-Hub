//
//  main.c
//  long number subtraction
//
//  Created by Steve X on 2017/11/14.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void PositiveMinus(int A[],int B[],int a,int b)
{
    int C[100],t=0;
    for(int i=0;i<100;i++){
        C[i]=0;
    }
    
    if(a>b)return;
    if(a==b){
        int i;
        for(i=a;i<100;i++){
            if(A[i]>B[i])break;
        }
        if(i==100){
            printf("0\n");
            return;
        }
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

int main()
{
    int A[100],B[100],a,b,x,y;
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
        A[a]=str1[x]-'0';
        x--;
    }
    for(b=99;y>=0;b--){
        B[b]=str2[y]-'0';
        y--;
    }
    a++;
    b++;
    PositiveMinus(A,B,a,b);
    return 0;
}
