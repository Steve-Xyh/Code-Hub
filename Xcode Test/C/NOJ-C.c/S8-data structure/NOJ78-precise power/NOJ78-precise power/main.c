//
//  main.c
//  NOJ78-precise power
//
//  Created by Steve X on 2017/11/14.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#define N 200

void multi(int A[],int B[],int a,int b,int r,int p)    //大数乘法
{
    int m[N][N],C[N],F[N],n,t,z=0;        //初始化m,C
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
    
    for(int i=N-1;i>=0;i--){
        F[i]=C[i];
    }
    
    for(t=0;F[t]==0;t++);
    r--;
    if(r>1)return multi(A,F,a,0,r,p);
    else{
        if(p>0){
            for(int i=N-1;i>=0;i--){
                if(i>=p&&z==0&&F[i]!=0)z++;
                if(z==1){
                    z=N-1-i;
                    break;
                }
            }
        }
        for(int i=t;i<N-z;i++){
            printf("%d",F[i]);
            if(i==p&&N-z-1!=p)printf(".");
        }
        printf("\n");
    }
}

int main()
{
    int A[N],a,x,r,p=0;
    char str1[N];
    scanf("%s%d",str1,&r);
    for(x=0;str1[x]!='\0';x++);
    x--;
    for(a=N-1;x>=0;a--){
            if(str1[x]=='.'){
                p=N-1-r*(N-1-a);
                x--;
            }
            A[a]=str1[x]-'0';
        x--;
    }
    a++;
    if(r>1)multi(A,A,a,a,r,p);
    else if(r==0)printf("1\n");
    else{
        for(int i=a;i<N;i++){
            printf("%d",A[i]);
        }
        printf("\n");
    }
    return 0;
}
