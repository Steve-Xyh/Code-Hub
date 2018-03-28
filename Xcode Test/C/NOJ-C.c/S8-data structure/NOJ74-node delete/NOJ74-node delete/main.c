//
//  main.c
//  NOJ74-node delete
//
//  Created by Steve X on 2017/11/12.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagElemType{
    int no;
    char name[12];
    int age;
}ElemType;

typedef struct tagLNode{
    ElemType data;
    struct tagLNode *next;
}LNODE,*LinkList;

void deletenode(LNODE *L,int n)
{
    LNODE *p=NULL,*q=NULL;
    q=L;
    while(q!=NULL){
        p=q;
        q=q->next;
        if(q->data.no==n)break;
    }
    p->next=q->next;
    free(q);
}

int main()
{
    int no,age,x;
    char name[12];
    LNODE *head=NULL,*p,*q=NULL,*t,*ori;
    //LinkList p;
    while(1){
        p=(LinkList)malloc(sizeof(LNODE));
        scanf("%d",&no);
        if(no!=0){
            scanf("%s%d",name,&age);
            p->data.no=no;
            strcpy(p->data.name,name);
            p->data.age=age;
            p->next=NULL;
        }
        else break;
        if(head==NULL)head=p;
        else q->next=p;
        q=p;
    }
    scanf("%d",&x);
    ori=head;
    while(ori->next!=NULL){
        printf("%d ",ori->data.no);
        ori=ori->next;
    }
    printf("%d\n",ori->data.no);
    /*
    p=head;                                 //删除结点
    while(p!=NULL){
        if(p->next->data.no==x){
            p->next=p->next->next;
            free(p->next);
            break;
        }
        p=p->next;
    }*/
    t=head;
    deletenode(t,x);
    while(t->next!=NULL){
        //if(t->data.no!=x)
            printf("%d ",t->data.no);
        t=t->next;
    }
    printf("%d\n",t->data.no);
    return 0;
}
