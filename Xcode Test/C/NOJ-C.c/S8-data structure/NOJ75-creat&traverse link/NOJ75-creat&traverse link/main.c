//
//  main.c
//  NOJ75-creat&traverse link
//
//  Created by Steve X on 2017/11/14.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct tagNODE{
    int no;
    struct tagNODE *next;
}NODE,*LinkList;

NODE *head=NULL,*p,*q=NULL;

void creatlink()
{
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        p=(LinkList)malloc(sizeof(NODE));
        p->no=x;
        p->next=NULL;
        if(head==NULL)head=p;
        else q->next=p;
        q=p;
    }
}

void list()
{
    NODE *t;
    t=head;
    while(t!=NULL){
        printf("%d ",t->no);
        t=t->next;
    }
    printf("\n");
}

int main()
{
    creatlink();
    list();
    return 0;
}
