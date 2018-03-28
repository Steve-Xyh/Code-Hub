//
//  main.c
//  NOJ62-file compare
//
//  Created by Steve X on 2017/11/4.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main()
{
    FILE *fp1,*fp2;
    //FILE *ppp;
    char f1[1000],f2[1000];
    //ppp=fopen("zxcvbnm.txt","w");
    fp1=fopen("DATA5613.TXT","r");
    fp2=fopen("DATA5613.CPP","r");
    if(fp1!=NULL&&fp2!=NULL){
        //printf("files opened\n");
        int i=0;
        while(!feof(fp1)){
            fgets(f1,sizeof(f1)-1,fp1);
            fgets(f2,sizeof(f2)-1,fp2);
            for(int j=0;f1[j]!='\0';j++){
                if(f1[j]!=f2[j])printf("%d %d\n",i+1,j+1);
            }
            i++;
        }
        fclose(fp1);
        fclose(fp2);
    }
    return 0;
}
