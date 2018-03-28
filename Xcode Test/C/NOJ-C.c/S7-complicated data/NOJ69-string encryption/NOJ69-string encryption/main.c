//
//  main.c
//  NOJ69-string encryption
//
//  Created by Steve X on 2017/11/9.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void strencode(char A[])
{
    for(int i=0;A[i]!='\0';i++){
        if('a'<=A[i]&&A[i]<='z')A[i]-=3;
        if('A'<=A[i]&&A[i]<='Z')A[i]+=3;
    }
    printf("%s\n",A);
}

int main()
{
    char A[500];
    gets(A);
    strencode(A);
    return 0;
}
