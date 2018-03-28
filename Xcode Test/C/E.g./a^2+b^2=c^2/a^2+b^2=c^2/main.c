//
//  main.c
//  a^2+b^2=c^2
//
//  Created by Steve X on 2017/12/2.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main()
{
    int a,b,c,A=1,B=1,C=1;
    for(a=0;a<=1000;a++){
        for(b=a+1;b<=1000-a;b++){
            for(c=b+1;c<=1000-b-a;c++){
                if(a*a+b*b==c*c&&a+b+c==1000){
                    A=a;
                    B=b;
                    C=c;
                    break;
                }
            }
        }
    }
    printf("%d^2+%d^2=%d^2\n%d\n",A,B,C,A*B*C);
    return 0;
}
