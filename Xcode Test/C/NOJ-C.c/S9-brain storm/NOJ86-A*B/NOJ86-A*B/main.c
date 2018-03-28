//
//  main.c
//  NOJ86-A*B
//
//  Created by Steve X on 2017/11/18.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#define N 100

void multi(int A[],int B[],int a,int b)
{
    int m[N][N],C[N],n,cnt=0,t,sum=0;        //初始化m,C
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            m[i][j]=0;
            C[j]=0;
        }
    }
    
    for(int j=N-1;j>=b;j--){              //乘法竖式进位
        for(int i=N-1;i>=a;i--){
            n=j+i-N+1;
            m[j][n]+=A[i]*B[j];
            if(m[j][n]>9){
                m[j][n-1]+=m[j][n]/10;
                m[j][n]%=10;
            }
            n--;
        }
    }
    
    for(int i=N-1;i>=0;i--){       //加法竖式进位
        for(int j=N-1;j>=b;j--){
            C[i]=C[i]+m[j][i];
        }
        if(C[i]>9){
            C[i-1]+=C[i]/10;
            C[i]%=10;
        }
    }
    
    for(t=0;C[t]==0;t++);
    cnt=N-t;
    if(cnt<2){
        for(int i=t;i<N;i++){
            printf("%d",C[i]);
        }
        printf("\n");
        return;
    }
    else{
        for(int i=t;i<N;i++){
            sum+=C[i];
        }
        while(sum>9){
            int a,b,c;
            a=sum/100;
            b=sum/10-a*10;
            c=sum%10;
            sum=a+b+c;
        }
        printf("%d\n",sum);
        return;
    }
}

int main()
{
    int A[N],B[N],a,b,x,y,cnt=0;
    char str1[N],str2[N];
    scanf("%s%s",str1,str2);
    for(x=0;str1[x]!='\0';x++);
    for(y=0;str2[y]!='\0';y++);
    x--;
    y--;
    for(a=N-1;x>=0;a--){
        if(str1[x]!='-')A[a]=str1[x]-'0';
        else{
            cnt++;
            break;
        }
        x--;
    }
    for(b=N-1;y>=0;b--){
        if(str2[y]!='-')B[b]=str2[y]-'0';
        else{
            cnt++;
            break;
        }
        y--;
    }
    a++;
    b++;
    multi(A,B,a,b);
    return 0;
}
