//
//  main.c
//  primenumber3
//
//  Created by Steve X on 2017/10/2.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*long n,i=2;
    scanf("%ld",&n);
    long m=labs(n);
    for(i=2;i<=n-1;i++){
        if(n%i==0)break;
    }
    if(m!=i)printf("%ld is not a prime number.\n",n);
    else printf("%ld is a prime number.\n",n);
    return 0;*/
    int n,i=2;
    scanf("%d",&n);
    int x=abs(n);
    for(i=2;i<=n-1;i++){
        if(n%i==0)break;
    }
    if(x!=i) return 0;
    else return 1;
}
