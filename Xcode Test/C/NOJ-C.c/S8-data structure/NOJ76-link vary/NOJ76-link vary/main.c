//
//  main.c
//  NOJ76-link vary
//
//  Created by Steve X on 2017/11/14.
//  Copyright © 2017年 Steve X. All rights reserved.
//
/*
#include <stdio.h>
#include <stdlib.h>

typedef struct tagNODE{
    int age;
    struct tagNODE *next;
}NODE,*LinkList;

NODE *head=NULL,*p,*q=NULL;

int deletenode(int n)
{
    int cont=0;
    NODE *p=NULL,*q;
    q=head;
    while(q->next!=NULL){
        p=q;
        q=q->next;
        if(q->age==n){
            cont++;
            break;
        }
    }
    p->next=q->next;
    free(q);
    return cont;
}

void creatlink()
{
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        if(i==0||deletenode(x)==0){
            p=(LinkList)malloc(sizeof(NODE));
            p->age=x;
            p->next=NULL;
            if(head==NULL)head=p;
            else q->next=p;
            q=p;
        }
        else deletenode(x);
    }
}

/*void deletenode(NODE *p)
{
    p=p->next;
    free(p);
}
*/
int main()
{
    head=NULL;
    creatlink();
    for(NODE *put=head;put!=NULL;put=put->next)printf("%d ",put->age);
    return 0;
}*/

