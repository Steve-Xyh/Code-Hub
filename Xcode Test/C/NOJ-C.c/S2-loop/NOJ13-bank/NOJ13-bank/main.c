//
//  main.c
//  NOJ13-bank
//
//  Created by Steve X on 2017/10/13.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <math.h>
double sum(double W,double X,double n)
{
    return W*pow(1+X,n);
}

int main()
{
    double A=0.63/100*12,B=0.66/100*12*2,C=0.69/100*12*3,D=0.75/100*12*5,E=0.84/100*12*8;
    int a,b,c,d,e,n1=0,n2=0,n3=0,n5=0,n8=0;//i=0;
    double s=0.0,max=0.0;//min=999999;
    for(a=0;a<21;a++){                             //此处循环顺序可任意
        for(b=0;b<11;b++){
            for(c=0;c<7;c++){
                for(d=0;d<=4;d++){
                    for(e=0;e<3;e++){
                        if(a+2*b+3*c+5*d+8*e<=20){
                            //i++;
                            s=2000;
                            s=sum(s,A,a);
                            s=sum(s,B,b);
                            s=sum(s,C,c);
                            s=sum(s,D,d);
                            s=sum(s,E,e);
                            //printf("%d %d %d %d %d,%lf\n",e,d,c,b,a,s);
                            if(s>=max)max=s;
                            //if(s<min)min=s;
                            if(s==max){
                                n8=e;n5=d;n3=c;n2=b;n1=a;
                            }
                        }
                    }
                }
            }
        }
    }
    //printf("\n共%d种方案\n",i);
    //printf("最佳方案%d %d %d %d %d\n",n8,n5,n3,n2,n1);
    //printf("最大收益%.2lf,最小收益%.2lf\n",max,min);
    printf("%d %d %d %d %d\n",n8,n5,n3,n2,n1);
    printf("%.2lf\n",max);
    return 0;
}
