//
//  main.c
//  NOJ52-Roman numerals transform
//
//  Created by Steve X on 2017/10/31.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int trans(char c[])
{
    char R[13][5]={{0},{"I"},{"II"},{"III"},{"IV"},{"V"},{"VI"},{"VII"},{"VIII"},{"IX"},{"X"},{"XI"},{"XII"}};
    int i,j;
    for(i=0;i<13;i++){
        for(j=0;j<4;j++){
            if(c[j]!=R[i][j])break;
        }
        if(j==4)break;
    }
    return i;
}

int main()
{
    char c[4];
    scanf("%s",c);
    printf("%d\n",trans(c));
    return 0;
}
