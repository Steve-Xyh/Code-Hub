//
//  main.c
//  NOJ21-fraction divide
//
//  Created by Steve X on 2017/10/17.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int k,x,y=1.0;
    scanf("%d",&k);
    /*clock_t start,finish;
    double totaltime;
    start=clock();*/
    
    
    for(y=k+1;y<=2*k;y++){
        if(k*y%(y-k)==0){
            x=k*y/(y-k);
            if(x>0)printf("1/%d=1/%d+1/%d\n",k,x,y);
        }
    }
    
    
    /*finish=clock();
    totaltime=(double)(finish-start)/CLOCKS_PER_SEC;
    printf("%lfs\n",totaltime);*/
    return 0;
}
