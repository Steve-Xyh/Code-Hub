//
//  main.c
//  NOJ30-division
//
//  Created by Steve X on 2017/10/26.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <time.h>

int judge(int m,int n)
{
    int a[10];
    for(int i=5;i<10;i++){
        a[i]=m%10;
        m=m/10;
    }
    for(int i=0;i<5;i++){
        a[i]=n%10;
        n=n/10;
    }
    
    int p,q,i=0;
    for(p=0;p<10;p++){
        for(q=0;q<10;q++){
            if(a[p]==a[q]&&p!=q)i++;
        }
    }
    if(i==0)return 1;
    else return 0;
}

int main()
{
    int n;
    long start,end;
    scanf("%d",&n);
    start=clock();
    
    int x=1234,y;
    for(;x*n<=98765;x++){
        y=x*n;
        if(judge(x,y)==1){
            //if(x<10000)printf("%d/0%d=%d\n",y,x,n);
            printf("%05d/%05d=%d\n",y,x,n);
        }
    }
    end=clock();
    printf("%ldms\n",end-start);
    return 0;
}
