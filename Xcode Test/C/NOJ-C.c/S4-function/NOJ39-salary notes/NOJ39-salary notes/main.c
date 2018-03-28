//
//  main.c
//  NOJ39-salary notes
//
//  Created by Steve X on 2017/10/29.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int five(int n)
{
    int s=0;
    if(n>=5)s++;
    switch (n%5){
        case 4:case 3:s=s+2;break;
        case 2:case 1:s++;break;
        case 0:;
    }
    return s;
}
int ten(int n)
{
    int s=n/10+five(n%10);
    return s;
}
int fifty(int n)
{
    int s=n/50+ten(n%50);
    return s;
}
int note(int n)
{
    int s=n/100+fifty(n%100);
    return s;
}

/*int a=100,b=50,c=10,d=5,e=2,f=1,n1,n2,n3,n4,n5,n6;

int note(int x)
{
    int s=0,min=1e9;
    for(n1=0;n1<=x/a;n1++){
        for(n2=0;n2<=x/b;n2++){
            for(n3=0;n3<=x/c;n3++){
                for(n4=0;n4<=x/d;n4++){
                    for(n5=0;n5<=x/e;n5++){
                        for(n6=0;n6<=x/f;n6++){
                            if(n1*100+n2*50+n3*10+n4*5+n5*2+n6*1==x){
                                s=n1+n2+n3+n4+n5+n6;
                                if(min>=s)min=s;
                            }
                        }
                    }
                }
            }
        }
    }
    return min;
}*/

int main()
{
    int n;
    scanf("%d",&n);
    int a[n],min=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        min=min+note(a[i]);
    }
    printf("%d\n",min);
    //printf("%d\n",note(a[2]));
    /*for(int i=0;i<n;i++){
        printf("%d,",a[i]);
        
    }*/
    return 0;
}
