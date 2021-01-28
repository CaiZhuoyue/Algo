#include<stdio.h>
#include<stdlib.h>
//用到欧几里得算法
using namespace std;

int gcd(int a, int b)
{
    if(b==0)
    return a;
    else
    return(gcd(b,a%b));
}

int gcd_(int a, int b)
{
    return !b?a:gcd(b,a%b);
}


int main()
{
    printf("%d\n",gcd_(14,49));

    return 0;
}
