//
//  main.c
//  NOJ55-string merge
//
//  Created by Steve X on 2017/11/1.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <string.h>
unsigned long i,len1,len2;

void stringmerge(char s1[],char s2[])
{
    for(i=0;i<len2;i++){
        s1[i+len1]=s2[i];
    }
}

int main()
{
    char s1[100],s2[100];
    scanf("%s",s1);
    scanf("%s",s2);
    len1=strlen(s1);
    len2=strlen(s2);
    stringmerge(s1,s2);
    printf("%s\n",s1);
    return 0;
}
