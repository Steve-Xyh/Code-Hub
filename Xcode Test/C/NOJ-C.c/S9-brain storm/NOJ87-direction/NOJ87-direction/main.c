//
//  main.c
//  NOJ87-direction
//
//  Created by Steve X on 2017/11/21.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <string.h>
int main()
{
    char direction[4][6]={"North","East","South","West"},D[6];
    int n,A[100],x=0,p=0,q=0;
    scanf("%s%d",D,&n);
    for(int i=0;i<4;i++){
        if(strcmp(direction[i],D)==0)p=i;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(A[i]==0)x--;
        if(A[i]==1)x++;
    }
    q=p+x%4;
    if(q>=0&&q<=3)p=q;
    else if(q>3)p=q-4;
    else p=q+4;
    printf("%s\n",direction[p]);
    return 0;
}
