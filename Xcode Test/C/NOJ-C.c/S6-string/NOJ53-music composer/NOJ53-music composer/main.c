//
//  main.c
//  NOJ52-Roman numerals transform
//
//  Created by Steve X on 2017/10/31.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

void music(char c[])
{
    char A[5][3]={{"A#"},{"C#"},{"D#"},{"F#"},{"G#"}};
    char B[5][3]={{"Bb"},{"Db"},{"Eb"},{"Gb"},{"Ab"}};
    int i,j=0,s=0;
    for(i=0;i<5;i++){
            if(c[j]!=A[i][j]&&c[j]!=B[i][j]){
                continue;
            }
            if(c[j]==A[i][j]&&c[j+1]==A[i][j+1]){
                printf("%s",B[i]);
                s++;
                break;
            }
            if(c[j]==B[i][j]&&c[j+1]==B[i][j+1]){
                printf("%s",A[i]);
                s++;
                break;
            }
        if(s>0)break;
    }
    if(i==5)printf("%s",c);
}

int main()
{
    char c[4],d[6];
    scanf("%s",c);
    scanf("%s",d);
    music(c);
    printf(" %s\n",d);
    return 0;
}
