#include<stdio.h>
#include<stdlib.h>
#include<cstring>

//把单词倒过来说 但是单词内字母顺序不会变
int main()
{
    int n=0;
    char ans[90][90];
    while(scanf("%s",ans[n])!=EOF)
    {
        n++;
    }
    for(int i=n;i>=0;--i)
    {
        printf("%s",ans[i]);
        if(i!=0)
            printf(" ");
    }
    return 0;
}