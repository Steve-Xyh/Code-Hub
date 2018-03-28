//
//  main.c
//  NOJ56-string cut&sort
//
//  Created by Steve X on 2017/11/1.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define N 1000
unsigned long i,j,n,len;
char t;

void up(char str[])                    //冒泡排序,升序
{
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(str[j]>str[j+1]){
                t=str[j];
                str[j]=str[j+1];
                str[j+1]=t;
            }
        }
    }
}

void down(char str[])                  //冒泡排序,降序
{
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(str[j]<str[j+1]){
                t=str[j];
                str[j]=str[j+1];
                str[j+1]=t;
            }
        }
    }
}

void sort(char str[],unsigned long n)
{
    char left[N],right[N];
    for(i=0;i<=n;i++){                //字符串左半部分复制
        left[i]=str[i];
    }
    j=0;
    for(i=len-n;i<=len;i++){          //字符串右半部分复制
        right[j]=str[i];
        j++;
    }
    down(left);                       //左降序，右升序
    up(right);
    
    for(i=0;i<n;i++){                 //将排序后的两个子串恢复到原字符串中
        str[i]=right[i];
    }
    j=0;
    for(i=len-n;i<len;i++){
        str[i]=left[j];
        j++;
    }
}

int main()
{
    char str[N];
    scanf("%s",str);
    len=strlen(str);                  //取字符串长度len
    n=len/2;
    
    sort(str,n);
    printf("%s\n",str);
    return 0;
}
