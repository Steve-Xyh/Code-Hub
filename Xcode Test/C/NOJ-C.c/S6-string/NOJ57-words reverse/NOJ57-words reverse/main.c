//
//  main.c
//  NOJ57-words reverse
//
//  Created by Steve X on 2017/11/2.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
char A[200],word[100][15];

void reverse(char A[200])
{
    int m=0,n=0;
    for(int i=0;A[i]!='\0';i++){
        for(int j=0;j<15;j++){
            if(A[m]!=' '&&A[m]!=','&&A[m]!='.'){
                word[n][j]=A[m];
                m++;
            }
            else break;
        }
        m++;
        n++;
        if(A[m]=='\0')break;
    }
    for(int i=n-1;i>=0;i--){
        printf("%s ",word[i]);
    }
    printf("\n");
}

int main()
{
    gets(A);
    reverse(A);
    return 0;
}
