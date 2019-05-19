//
//  main.cpp
//  Y-A==B?
//
//  Created by Steve X on 2017/12/27.
//  Copyright © 2017年 Steve X. All rights reserved.
//

#include <cstdio>
#include <cstring>
char a[100017], b[100017];
void re(char s[])
{
    int len = strlen(s);
    int p = 0;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '.')
        {
            p = 1;
            break;
        }
    }
    if(p)
    {
        for(int i = len-1; i >= 0; i--)
        {
            if(s[i] == '0')
                s[i] = '\0';
            else
                break;
            len--;
        }
        if(s[len-1] == '.')
            s[len-1] = '\0';
    }
}
int main()
{
    while(~scanf("%s%s",a,b))
    {
        re(a);
        // printf("%s\n",a);
        re(b);
        // printf("%s\n",b);
        if(strcmp(a,b))
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
