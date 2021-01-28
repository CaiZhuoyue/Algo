#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
/*
    * 库存 总售价可以都设置为double
    * 市场需求d 也可以设置为double
*/

struct cake{
    int kc;
    int sj;
    double uv;//单位重量的价格
} mc[30];

bool cmp(cake c1,cake c2)
{
    return c1.uv>c2.uv;
}
int main()
{
    int n;//种数
    int d;//市场需求
    
    scanf("%d%d",&n,&d);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&mc[i].kc);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&mc[i].sj);
        mc[i].uv=(((double)mc[i].sj)/((double)mc[i].kc));
    }
    sort(mc,mc+n,cmp);
    double ans=0.0;
    for(int i=0;i<n;i++)
    {
        if(d<=mc[i].kc)//库存小于需求
           {
               ans+=mc[i].uv*(double)d;
               break;
            }
        else //库存大于需求
        {
            d-=mc[i].kc;
            ans+=mc[i].sj;
        }
    }

    printf("%.2lf\n",ans);

    return 0;
}
