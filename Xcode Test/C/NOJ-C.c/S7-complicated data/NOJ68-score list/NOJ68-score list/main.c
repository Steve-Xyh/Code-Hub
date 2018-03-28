//
//  main.c
//  NOJ68-score list
//
//  Created by Steve X on 2017/11/9.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

typedef struct tagstudent{
    long number;
    char name[12];
    int age;
    double score[7];
    double sum;
    double ave;
} STUDENT;

int main()
{
    STUDENT A[10],max;
    max.sum=0;
    for(int i=0;i<10;i++){
        scanf("%ld%s%d",&A[i].number,A[i].name,&A[i].age);
        A[i].sum=0;
        for(int j=0;j<7;j++){
            scanf("%lf",&A[i].score[j]);
            A[i].sum+=A[i].score[j];
        }
        A[i].ave=A[i].sum/7;
        if(A[i].sum>max.sum)max=A[i];
    }
    printf("%ld %s %d ",max.number,max.name,max.age);
    for(int i=0;i<7;i++){
        printf("%.2lf ",max.score[i]);
    }
    printf("\n");
    return 0;
}
