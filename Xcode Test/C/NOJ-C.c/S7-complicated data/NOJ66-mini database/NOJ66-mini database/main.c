//
//  main.c
//  NOJ66-mini database
//
//  Created by Steve X on 2017/11/9.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

typedef struct STUDENT{
    int number;
    char name[12];
    int score;
}STUDENT;

void max(struct STUDENT a[],int n)
{
    struct STUDENT max;
    max.score=0;
    for(int j=0;j<n;j++){
            if(a[j].score>max.score)max=a[j];
    }
    printf("%d %s %d\n",max.number,max.name,max.score);
}

int main()
{
    FILE *fp;
    int n;
    STUDENT a[50];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%s%d",&a[i].number,a[i].name,&a[i].score);
    }
    
    fp=fopen("DATA5614.DB","w");
    if(fp!=NULL){
        fprintf(fp,"%d\n",n);
        for(int i=0;i<n;i++){
            fprintf(fp,"%d %s %d\n",a[i].number,a[i].name,a[i].score);
        }
        fclose(fp);
    }
    
    fp=fopen("DATA5614.DB","r");
    if(fp!=NULL){
        fscanf(fp,"%d",&n);
        for(int i=0;i<n;i++){
            fscanf(fp,"%d %s %d",&a[i].number,a[i].name,&a[i].score);
        }
        max(a,n);
        fclose(fp);
    }
    return 0;
}
