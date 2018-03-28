//
//  main.c
//  NOJ65-string remix
//
//  Created by Steve X on 2017/11/8.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#define N 500
char str1[N],str2[N];

void fun(char *s,char *t)
{
    int j=0;
    for(int i=0;i<N;i++){
        //int str1[i],str2[i];
        if((i%2!=0)&&(str1[i]%2!=0)){
            str2[j]=str1[i];
            j++;
        }
    }
    str2[j]='\0';
    printf("%s\n",str2);
}

int main()
{
    char *s=str1;
    char *t=str2;
    gets(str1);
    fun(s,t);
    return 0;
}
