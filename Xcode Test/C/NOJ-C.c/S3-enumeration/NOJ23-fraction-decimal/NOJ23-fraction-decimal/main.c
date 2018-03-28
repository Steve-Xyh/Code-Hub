//
//  main.c
//  NOJ23-fraction-decimal
//
//  Created by Steve X on 2017/10/17.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <math.h>

int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int d=a/b,e=a,f;
    //double g=0,x;
    printf("%d.",d);
    for(int i=1;i<=c;i++){
        f=10*e/b;
        //g=g+f*pow(10,-i);
        if(i==c&&f>=5)printf("%d",f+1);
        else printf("%d",f);
        e=10*e%b;
    }
    //x=(int)((d+g)*pow(10,c)+0.5)/pow(10,c);
    //printf("%.*lf\n",c,x);
    printf("\n");
    return 0;
}

/*int po_10(int a)
 {
 int pro=1;
 for(;a>=1;a--)
 pro*=10;
 return pro;
 }
 
 int main()
 {
 int a,b,c;
 double xx;
 scanf("%d%d%d",&a,&b,&c);
 xx=(double)a/b;
 xx*=po_10(c);
 xx=(int)xx;
 xx/=po_10(c);
 printf("%g\n",xx);
 return 0;
 }*/
