#include<stdio.h>
#include<stdlib.h>
using namespace std;

const int maxn=30;
int prime[10];

struct factor
{
    int x;//质因子
    int cnt;//出现次数
}fac[10];
//fac数组只需要开到10
//因为前10个质数相乘的结果已经大于int范围

void PrimeGen()
{
    int count=0;
    bool isprime[30]={0};
    for(int i=2;count<10;i++)
    {
        if(!isprime[i])
        {
            prime[count++]=i;
            for(int j=i*i;j<maxn;j+=i)
            {
                isprime[j]=1;
            }
        }
    }
    return;
}


int main()
{
    int n=18920;
    PrimeGen();
    for(int i=0;i<10;i++)
    {
        int cnt=0;
        while(n%prime[i]==0)
        {
            cnt++;
            n/=prime[i];
        }
        fac[i].x=prime[i];
        fac[i].cnt=cnt;
    }
    for(int i=0;i<10;i++)
    {
        if(fac[i].cnt!=0)
            printf("%d 的次数是 %d\n",fac[i].x,fac[i].cnt);
    }

    
    return 0;
}
