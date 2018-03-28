//
//  main.c
//  reverse number
//
//  Created by Steve X on 2017/10/10.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d",&n);//输入要翻转的数字
    int result = 0;//保存翻转后的结果
    while(1)//while(true)也可以
    {
        int i = n%10;//每次都是得到最低位上的数字
        result = result*10+i;
        n = n/10;//递归降位
        if(n == 0)break;
    }
    printf("翻转后的数字是%d\n",result);
}
