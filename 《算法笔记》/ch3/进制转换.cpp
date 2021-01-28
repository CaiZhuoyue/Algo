#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a,b,d;
    printf("输入abd\n");
    scanf("%d%d%d",&a,&b,&d);
    a+=b;
    int ans[31];
    int k=0;
    while(a>=d)
    {
        ans[k++]=a%d;
        a/=d;
    }
    ans[k++]=a; //这里要重点注意！
    
    //写法2：
    // do {
    //     ans[k++]=a%d;
    //     a/=d;
    // }
    // while(a!=0);
    // 这里用do while而不用while是考虑到a+b=0的情况

    //写法3:
    // if(a==0)
    //     ans[k++]=0;
    // while(a!=0)
    // {
    //     ans[k++]=a%d;
    //     a/=d;
    // }
    
    for(k=k-1;k>=0;k--)
    {
        printf("%d\n",ans[k]);
    }
    return 0;
}