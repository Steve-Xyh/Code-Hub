//
//  main.c
//  NOJ72-long number multiply
//
//  Created by Steve X on 2017/11/10.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void multi(int A[],int B[],int a,int b)
{
    int m[100][200],C[200],n=199,t;//s=199,t;   //初始化m,C
    for(int i=0;i<100;i++){
        for(int j=0;j<200;j++){
            m[i][j]=0;
            C[j]=0;
        }
    }
    
    for(int j=99;j>=b;j--){              //乘法竖式进位
        for(int i=99;i>=a;i--){
            n=j+i;
            m[j][n]+=A[i]*B[j];
            if(m[j][n]>9){
                m[j][n-1]+=m[j][n]/10;
                m[j][n]%=10;
            }
            n--;
        }
        //s--;
    }
    
    /*检验加法竖式
    printf("\n");
    for(int j=99;j>=b;j--){
        for(int i=a;i<100;i++){
            n=j+i;
            printf("%d",m[j][n]);
            n--;
        }
        printf("\n");
    }
    printf("\n");*/
    
    for(int i=199;i>=a;i--){       //加法竖式进位
        for(int j=99;j>=b;j--){
            C[i]=C[i]+m[j][i];
        }
        if(C[i]>9){
            C[i-1]+=C[i]/10;
            C[i]%=10;
        }
    }
    
    for(t=0;C[t]==0;t++);
    //printf("A*B=");
    for(int i=t;i<199;i++){
        printf("%d",C[i]);
    }
    printf("\n");
    
    /*检验乘法竖式
    for(int j=99;j>=0;j--){
        for(int i=0;i<199;i++){
            printf("%d",m[j][i]);
        }
        printf("\n");
    }*/
    
}

int main()
{
    int A[100],B[100],a,b,x,y,cnt=0;
    char str1[100],str2[100];
    gets(str1);
    gets(str2);
    for(x=0;str1[x]!='\0';x++);
    for(y=0;str2[y]!='\0';y++);
    x--;
    y--;
    for(a=99;x>=0;a--){
        if(str1[x]!='-')A[a]=str1[x]-'0';
        else{
            cnt++;
            break;
        }
        x--;
    }
    for(b=99;y>=0;b--){
        if(str2[y]!='-')B[b]=str2[y]-'0';
        else{
            cnt++;
            break;
        }
        y--;
    }
    a++;
    b++;
    
    /*验证字符串，数组输入
    printf("\nstr1:%s\nstr2:%s\n",str1,str2);
    printf("\nA=");
    for(int i=a;i<100;i++){
        printf("%d",A[i]);
    }
    printf("\nB=");
    for(int i=b;i<100;i++){
        printf("%d",B[i]);
    }
    printf("\n");*/
    
    if(cnt%2!=0)printf("-");
    multi(A,B,a,b);
    return 0;
}
