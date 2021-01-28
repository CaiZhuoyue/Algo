#include<stdio.h>
const int maxn=10010;

int main()
{
    int school[maxn]={0};
    int n,id,score;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d %d",&id,&score);
        school[id]+=score;
    }
    int k=1,MAX=-1;
    for(int i=1;i<=n;++i)
    {
        if(school[i]>MAX)
        {
            k=i;
            MAX=school[i];
        }
    }
    printf("%d %d\n",k,MAX);




    
}