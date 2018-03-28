//
//  main.c
//  NOJ84-symmetrical string
//
//  Created by Steve X on 2017/11/17.
//  Copyright © 2017年 Steve X. All rights reserved.
//
/*
#include <stdio.h>
#include <string.h>
#define N 5000

int alpha(char c)
{
    if(('a'<=c&&c<='z')||('A'<=c&&c<='Z'))return 1;
    else return 0;
}

int main()
{
    char str1[N]={"\0"},str2[N]={"\0"};
    //char *p1=str1,*p2=str2;
    gets(str1);
    int i,p,j=0,a=1;
    for(i=0;i<N;i++){
        while(j<N){
            if(alpha(str1[j])==1){
                str2[i]=str1[j];
                j++;
                break;
            }
            j++;
        }
    }
    for(p=1;p<strlen(str2)-1;p++){
        if(str2[p-1]==str2[p+1]){
            while(str2[p-a]==str2[p+a]){
                a++;
            }
            break;
        }
    }
    a--;
    printf("str1:%s\nstr2:%s\n",str1,str2);
    for(int i=p-a;i<=p+a;i++){
        printf("%c",str2[i]);
    }
    printf("\n");
    return 0;
}*/
//最长回文子串
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[5000],b[5000],i,j=0,c[5000],p=0,h,s;
    gets(a);
    for(i=0;i<strlen(a);i++){
        if(a[i]>=48&&a[i]<=57){b[j]=a[i];j++;}
        if(a[i]>=65&&a[i]<=90){b[j]=a[i];j++;}
        if(a[i]>=97&&a[i]<=122){b[j]=a[i];j++;}
    }
    for(i=1;i<strlen(b);i++){
        h=0;
        if(b[i]==b[i+1]){
            for(j=1;i-j+1>=0&&i+j<strlen(b);j++)
                if(b[i-j+1]==b[i+j]||abs(b[i-j+1]-b[i+1])==32) h++;
            else break;
        }
        if(h>p){
            p=h;
            for(s=i-j+2;s<i+j;s++)
                c[s-i+j-2]=b[s];
        }
        h=0;
        if(b[i-1]==b[i+1]){
            for(j=1;i-j>=0&&i+j<strlen(b);j++) if(b[i-j]==b[i+j]||abs(b[i-j]-b[i+j])==32) h++;
            else break;
        }
        if(h>p){
            p=h;
            for(s=i-j+1;s<i+j;s++)
                c[s-i+j-1]=b[s];
        }
    }
    for(i=0;i<strlen(a);i++)
        if(a[i]==c[0]) break;
    for(j=strlen(a);j>0;j--)
        if(a[j]==c[strlen(c)-1]) break;
    for(s=i;s<=j;s++)
        printf("%c",a[s]);
    printf("\n");
    return 0;
}
