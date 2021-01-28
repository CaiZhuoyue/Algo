#include<stdio.h>
int main()
{
    int n;
    int step=0;
    printf("input n:");
    scanf("%d",&n);
    while(n!=1)
    {
        step++;
        if(n&1)
        {
            n=3*n+1;
        }
        n/=2;
    }
    printf("%d\n",step);

}