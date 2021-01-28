#include<stdio.h>
#include<stdlib.h>
using namespace std;

//最小公倍数是在最大公约数的基础上

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

int acf(int a, int b)
{
    int d=gcd(a,b);
    return (a/d)*b;
}


int main()
{
    printf("%d\n",gcd(6,99));
    printf("%d\n",acf(6,99));
    

    
    return 0;
}
