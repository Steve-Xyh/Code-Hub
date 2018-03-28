//
//  main.c
//  NOJ47-2D array minus
//
//  Created by Steve X on 2017/10/31.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

/*int minus(int A[])
{
    
    int out=0,in=0;
    if(i=)
    
}*/

int main()
{
    int A[100][100],n,m,in=0,out=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&A[i][j]);
            if(i==0||i==n-1||j==0||j==m-1)out=out+A[i][j];
            else in=in+A[i][j];
        }
    }
    printf("%d\n",out-in);
    return 0;
}
