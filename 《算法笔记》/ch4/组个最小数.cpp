#include<stdio.h>
#include<stdlib.h>

using namespace std;
int num[10];
int ans[10010];

int main()
{
    int sum=0;
    for(int i=0;i<10;i++)
    {   
        scanf("%d",&num[i]);
        sum+=num[i];
    }

    for(int i=0;i<sum;i++)
    {
        int j;
        if(sum!=0 && i==0)
        {
            j=1;
        }
        else
        {
            j=0;
        }
        while(num[j]==0&&j<10)
        {
            j++;
        }
        // printf("找到了：%d\n",j);
        num[j]=num[j]-1;
        ans[i]=j;
    }

    for(int i=0;i<sum;++i)
    {
        printf("%d",ans[i]);
    }
    printf("\n");
    return 0;
}
