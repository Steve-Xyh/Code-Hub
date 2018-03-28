//
//  main.c
//  NOJ60-string alter
//
//  Created by Steve X on 2017/11/3.
//  Copyright &#169; 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int main()
{
    char A[1000];
    gets(A);
    
    int m=0,n=0;
    char B[100][20];
    for(int i=0;A[i]!='\0';i++){
        
        for(int j=0;j<20;j++){
            if(A[m]!=' '){
                if(((m==0)||(m>0&&!(('a'<=A[m+3]&&A[m+3]<='z')||('A'<=A[m+3]&&A[m+3]<='Z'))))&&A[m]=='y'&&A[m+1]=='o'&&A[m+2]=='u'&&!(('a'<=A[m+3]&&A[m+3]<='z')||('A'<=A[m+3]&&A[m+3]<='Z'))){
                    B[n][j]='w';
                    B[n][j+1]='e';
                    B[n][j+2]=A[m+3];
                    B[n][j+3]='\0';
                    m=m+4;
                    break;
                }
                else {
                    B[n][j]=A[m];
                    m++;
                }
            }
            else {
                B[n][j]=' ';
                B[n][j+1]='\0';
                m++;
                break;
            }
        }
        
        n++;
        //if(A[m]=='\0')break;
    }
    for(int i=0;i<=n;i++){
        printf("%s",B[i]);
    }
    printf("\n");
    
    return 0;
}

/*#include<stdio.h>
#include<string.h>
int main()
{
    char a[1010];
    
    while(gets(a)){
        
        unsigned long i,len=strlen(a);
        //int j=0,k=0;
        for(i=0;i<len;i++)
        {
            if(a[i]=='y'&&a[i+1]=='o'&&a[i+2]=='u')
            {
                printf("we");
                i=i+2;
            }
            else   printf("%c",a[i]);
            
        }
        printf("\n");
        break;
    }
 
    return 0;
}*/
