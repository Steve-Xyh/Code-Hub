//
//  main.c
//  NOJ63-words frequency
//
//  Created by Steve X on 2017/11/4.
//  Copyright © 2017年 Steve X. All rights reserved.
//
/*
#include <stdio.h>
#include <string.h>

int letter(char c)
{
    if(('a'<=c&&c<='z')||('A'<=c&&c<='Z'))return 1;      //判断是否为字母
    else return 0;
}

int main()
{
    FILE *fp1;
    char f1[500],str[20];
    int a=0,b=0,c=0;
    fp1=fopen("DATA5610.txt","r");
    if(fp1!=NULL){
        //printf("files opened\n");
        
        while(!feof(fp1)){
            int s=0;
            //fscanf(fp1,"%s",f1);
            fgets(f1,sizeof(f1)-1,fp1);
            //printf("检验输出F1:%s\n",f1);
            do{
                for(int j=0;j<20;j++){                    //分离单词
                    if(letter(f1[s])==1){
                        str[j]=f1[s];
                        s++;
                    }
                    else {
                        str[j]='\0';                      //判断单词字符串是否相等，随后跳出循环读取下一个单词
                        //printf("检验输出STR:%s\n",str);
                        if(strcmp(str,"if")==0)a++;
                        if(strcmp(str,"while")==0)b++;
                        if(strcmp(str,"for")==0)c++;
                        break;
                    }
                }
                s++;                                      //s表示原文字符串的下标
            }while(f1[s]!='\0');
        }
        fclose(fp1);
    }
    printf("%d %d %d\n",a,b,c);
    return 0;
}*/





/*NOJ提交
//
//  main.c
//  NOJ62-file compare
//
//  Created by Steve X on 2017/11/4.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int letter(char c)
{
    if(('a'<=c&&c<='z')||('A'<=c&&c<='Z'))return 1;
    else return 0;
}

int main()
{
    FILE *fp1;
    //FILE *ppp;
    char f1[500][15];
    int a=0,b=0,c=0,i=0;
    //ppp=fopen("zxcvbnm.txt","w");
    fp1=fopen("DATA5610.TXT","r");
    if(fp1!=NULL){
        //printf("files opened\n");
        
        while(!feof(fp1)){
            fscanf(fp1,"%s",f1[i]);
            int j=0;
            for(int i=0;letter(fgetc(fp1))!=0;i++){
                f1[i][j]=fgetc(fp1);
                j++;
            }
            if(strcmp(f1[i],"if")==0)a++;
            if(strcmp(f1[i],"while")==0)b++;
            if(strcmp(f1[i],"for")==0)c++;
            i++;
        }
        fclose(fp1);
    }
    printf("%d %d %d\n",a,b,c);
    return 0;
}
*/


//ACM
#include<stdio.h>
int nif,nwhile,nfor;
void chcl(char *s)
{
    int i;
    for(i=0;i<1000;i++)
        *(s+i)=0;
}
void Searchif(char *t)
{
    if(*t!='i')return;
    else
    {
        t++;
        if(*t!='f')return;
        else
        {
            nif++;
            return;
        }
    }
}
void Searchwhile(char *t)
{
    int i;
    char m[6]="while";
    for(i=0;i<5;i++)
    {
        if(*t!=m[i])return;
        else t++;
    }
    nwhile++;
}
void Searchfor(char *t)
{
    int i;
    char m[4]="for";
    for(i=0;i<3;i++)
    {
        if(*t!=m[i])return;
        else t++;
    }
    nfor++;
}
int main()
{
    FILE *fin=fopen("DATA5610.TXT","r");
    char s[1000]={0};
    char *p=NULL;
    nif=0,nwhile=0,nfor=0;
    while(fgets(s,900,fin)!=NULL)
    {
        p=s;
        while(*p!=0)
        {
            Searchif(p);
            Searchwhile(p);
            Searchfor(p);
            p++;
        }
        chcl(s);
    }
    fclose(fin);
    printf("%d %d %d\n",nif,nwhile,nfor);
    return 0;
}
