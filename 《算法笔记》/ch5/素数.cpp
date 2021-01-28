#include<stdio.h>
#include<stdlib.h>
#include<math.h>
using namespace std;


bool isPrime1(int n)
{
    //直接判断n能不能被2~n-1中的数字整除
    //复杂度O(n)
    if(n<=1)
        return false;
    for(int i=2;i<n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}

bool isPrime2(int n)
{
    //判断n能不能被2～sqrt(n)中的数字整除
    //因为如果2～n-1中存在n的约数k n%k=0 
    //那么k和(n/k)定满足一个大于sqrt(n) 一个小于sqrt(n)
    //复杂度O(sqrt(n))
    if(n<=1)
        return false;
    int sqr=(int)sqrt(1.0*n);
    for(int i=2;i<=sqr;i++)
    {
        if(n%i==0)
            return false;
    }
    return true;
}

bool isPrime3(int n)
{
    //如果n没有接近int变量的范围上界
    if(n<=1)
        return false;
    for(int i=2;i*i<n;i++)
    {
        if(n%i==0) return false;
    }
    return true;
}

void Find_Prime(int y)
{
    int count=0;
    for(int i=1;i<=y;i++)
    {
        if(isPrime2(i))
        {
            printf("%5d ",i);
            count++;
            if(count%5==0)
            printf("\n");
        }
    }
}



void Find_Prime2(int y)
{
    //“筛法”求素数-更高效的方式
    //对于一个数 如果没被前面步骤筛走就是素数 
    //对于素数筛掉它的所有倍数
    int Prime[10010]={0};
    for(int i=2;i<=y;i++)
    {
        if(!Prime[i])
        {
            printf("%d ",i);
            for(int j=2*i;j<=y;j+=i)
            {
                Prime[j]=1;
            }
        }   
    }
}

void Find_Prime3(int x, int y)
{
    //输出x～y范围内
    int Prime[10010]={0};
    for(int i=2;i<=y;i++)
    {
        if(!Prime[i])
        {
            for(int j=i+i;j<=y;j+=i)
                Prime[j]=1;
        }
    }
    for(int i=x;i<=y;i++)
    {
        if(!Prime[i])
            printf("%d ",i);
    }
    printf("\n");
}


void Find_Prime4(int x, int y)
{
    //输出Px～Py范围内
    //第x～y个素数
    int isPrime[100001]={0};
    int Primes[100];
    int max=100001;
    int count=1;
    for(int i=2;count<=y;i++)
    {
        if(!isPrime[i])
        {
            for(int j=i+i;j<max;j+=i)
            {
                isPrime[j]=1;
            }
            Primes[count++]=i;
        }
    }
    for(int i=x;i<=y;i++)
    {
        printf("%d ",Primes[i]);
    }
    printf("\n");
}


int main()
{
    Find_Prime4(5,27);
    return 0;
}
