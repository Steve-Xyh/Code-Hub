//
//  main.c
//  NOJ16-list
//
//  Created by Steve X on 2017/10/31.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main()
{
    char A[3]={'X','Y','Z'};
    for(int a=0;a<3;a++){
        for(int b=0;b<3;b++){
            for(int c=0;c<3;c++){
                if(a!=0&&c!=0&&c!=2&&a!=b&&a!=c&&b!=c){
                    printf("A=%c\nB=%c\nC=%c\n",A[a],A[b],A[c]);
                }
            }
        }
    }
    return 0;
}
