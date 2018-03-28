//
//  main.c
//  NOJ51-passage statistics
//
//  Created by Steve X on 2017/10/31.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
int LETTER=0,letter=0,n=0,space=0,other=0,i=0;
int c;

void PassageStatis()
{
    for(;;){
        c=getchar();
        if(c>='A'&&c<='Z')LETTER++;
        if(c>='a'&&c<='z')letter++;
        if(c>='0'&&c<='9')n++;
        if(c==' ')space++;
        if(c=='\n')i++;
        other++;
        if(i==3)break;
    }
    other-=LETTER+letter+n+space+i;
    printf("%d %d %d %d %d\n",LETTER,letter,n,space,other);
}

int main(){
    PassageStatis();
    return 0;
}
