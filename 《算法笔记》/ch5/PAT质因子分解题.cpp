
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int primes[]={2,3,5,7,11,13,17,19,23,29};



int main()
{
    int n=97532468;
    int flag=0;
    for(int i=0;i<10;i++)
    {
        int count=0;
        while(n%primes[i]==0)
        {
            count++;
            n/=primes[i];
        }
        if(count==0)
            continue;
        else
        {
            if(flag)
            {
                printf("*%d",primes[i]);
                if(count>1)
                    printf("^%d",count);
            }   
            else
            {
                printf("%d",primes[i]);
                if(count>1)
                    printf("^%d",count);
                flag=1;
            }
        }
    }
    
    return 0;
}
