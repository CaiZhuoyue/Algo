#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

bool cmp(int a, int b)//递减的序列
{
    return a>b;
}

void to_array(int a, int num[])
{
    for(int i=0;i<4;i++)
    {
        num[i]=a%10;
        a/=10;
    }
    return;
}

int to_num(int num[])
{
    int sum=num[0]*1000+num[1]*100+num[2]*10+num[3];
    return sum;
    
}


int main()
{
    int n,max,min;
    int num[4];
    scanf("%d",&n);
    while(n!=6174&&n!=0)
    {
        to_array(n,num);
        sort(num,num+4,cmp);
        max=to_num(num);
        sort(num,num+4);
        min=to_num(num);
        n=max-min;
        printf("%d-%d=%04d\n",max,min,n);
    }
    return 0;
}
