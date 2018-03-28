//
//  main.c
//  NOJ48-2D array print
//
//  Created by Steve X on 2017/10/31.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main() {
    int A[100][100],n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&A[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j)printf("%d ",A[i][j]);
            else printf("  ");
        }
        printf("\n");
    }
    return 0;
}
