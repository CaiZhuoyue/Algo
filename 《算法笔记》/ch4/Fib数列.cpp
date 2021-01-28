#include<stdlib.h>
#include<stdio.h>

//我写的非递归版本
int Fib(int n) 
{
    //输出第n个Fib数列
    int Fib[]={1,1};
     if(n<=2)
    {
        return 1;
    } 
    int temp;  
    while(n>0)
    {
        n--;
        temp=Fib[1];
        Fib[1]+=Fib[0];
        Fib[0]=temp;
        printf("%d ",Fib[1]);
    }
    printf("\n");
}

//我写的递归版本
int Fib_(int n)
{
    if(n<=2)
    return 1;
    else
    return Fib_(n-1)+Fib_(n-2);
}


int main()
{
    Fib(8);
    printf("%d\n",Fib_(10));
}