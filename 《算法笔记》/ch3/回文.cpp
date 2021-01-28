#include<stdlib.h>
#include<stdio.h>
#include<cstring>

const int maxn=256;

//codeup 5901
//判断是否是回文
bool judge(char str[])
{
    int length=strlen(str);
    for(int i=0;i<length/2;++i)
    {
        if(str[i]!=str[length-1-i])
            return false;
    }
    return true;

}

int main()
{
    char str[maxn];
    printf("输入字符串：");
    scanf("%s",str);
    if(judge(str))
        printf("是回文\n");
    else
        printf("不是\n");

}

