#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;
struct interval
{
    int x;
    int y;
} I[10010];

bool cmp(interval i1,interval i2)
{
    return i1.y<i2.y;
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d %d",&I[i].x,&I[i].y);
    }
    sort(I,I+n,cmp);
    int x=I[0].x;
    int y=I[0].y;
    for(int i=0;i<n;++i)
    {
        if(i==0)
            printf("(%d,%d)\n",x,y);
        else
        {
            if(y<=I[i].x)
            {
                printf("(%d,%d)\n",I[i].x,I[i].y);
                y=I[i].y;
            }
        }
    }
    
    return 0;
}
