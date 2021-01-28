#include<stdio.h>
#include<stdlib.h>

char c[]={'a','b','c','d','e','f'};
bool used[]={false};
char ans[100]={};

void Perm(int n, int k)//n是总长度 k是已经排列好的长度
{
    if(k>=n)
    {
        printf("%s\n",ans);
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!used[i])
        {
            ans[k]=c[i];
            used[i]=1;
            Perm(n,k+1);
            used[i]=0;
        }
    }

}


int main()
{
    Perm(3,0);

}