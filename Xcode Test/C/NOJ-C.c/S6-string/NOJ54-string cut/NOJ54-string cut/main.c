//
//  main.c
//  NOJ54-string cut
//
//  Created by Steve X on 2017/11/1.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <string.h>
unsigned long i;
char src[50],dest[50];

void Left(char src[],int n)
{
    for(i=0;i<n;i++){
        dest[i]=src[i];
    }
    for(i=0;i<n;i++){
        printf("%c",src[i]);
    }
    printf("\n");
}

void Right(char src[],int n,unsigned long len)
{
    for(i=len-n;i<len;i++){
        dest[i]=src[i];
    }
    for(i=len-n;i<len;i++){
        printf("%c",src[i]);
    }
    printf("\n");
}

void Mid(char src[],int loc,int n,unsigned long len)
{
    for(i=loc;i<loc+n;i++){
        dest[i]=src[i];
    }
    for(i=loc;i<loc+n;i++){
        printf("%c",src[i]);
    }
    printf("\n");
}

int main()
{
    int n,loc;
    unsigned long len;
    scanf("%s",src);
    len=strlen(src);
    scanf("%d%d",&n,&loc);
    Left(src,n);
    Right(src,n,len);
    Mid(src,loc,n,len);
    //printf("%s",src);
    return 0;
}
