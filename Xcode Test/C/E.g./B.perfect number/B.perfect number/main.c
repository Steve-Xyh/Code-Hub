//
//  main.c
//  B.perfect number
//
//  Created by Steve X on 2017/10/5.
//  Copyright © 2017年 apple. All rights reserved.
//

#include <stdio.h>

int main()
{
    int n;
    printf("Please input a number.\n");
    scanf("%d",&n);
    if(n<=2)printf("Error,please let n>2\n");
    int i,sum=1;
    for(i=2;i<n;i++){
        if(n%i==0)sum=sum+i;
    }
    printf("sum=%d\n",sum);
    if(sum==n)printf("YES\n%d is a perfect number.\n",n);
    else printf("NO\n");
    return 0;
}
