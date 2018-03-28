//
//  main.c
//  NOJ29-inequation
//
//  Created by Steve X on 2017/10/26.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a,b,n1=1,n2;
    scanf("%d%d",&a,&b);
    double x=0,f=0;
    for(int i=1;;i++){
        x=x+1.0/i;
        f=f+1.0/x;
        if(f<=a){
            n1++;
        }
        if(f>=b){
            n2=i-1;
            break;
        }
    }
    if(n1==n2)printf("%d\n",n1);
    else printf("%d %d\n",n1,n2);
    return 0;
}

/*double f(int n)
{
    double a=0,f=0;
    for(int i=1;i<=n;i++){
            a=a+1.0/i;
            f=f+1.0/a;
    }
    return f;
}

int main()
{
    int a,b,n1,n2;
    //printf("%lf",f(2));
    scanf("%d%d",&a,&b);
    n1=a;
    while(f(n1)<=a){
        n1=2*n1;
    }
    while(f(n1)>=a){
        n1=n1-n1/2;
    }
    while(f(n1)<=a){
        n1++;
    }
    
    
    n2=n1;
    while(f(n2)<b){
        n2=n2+10;
    }
    while(f(n2)>=b){
        n2--;
    }
    if(n1==n2)printf("%d\n",n1);
    else printf("%d %d\n",n1,n2);
    return 0;
}*/
