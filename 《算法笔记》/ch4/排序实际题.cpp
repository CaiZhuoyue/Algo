#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<cstring>
using namespace std;

struct student
{
    int score;
    int room;
    char id[15];
    int rank;//考场内排名
}stu[30010];

bool cmp(student a, student b)
{
    if(a.score!=b.score)
        return a.score>b.score;
    else
        return strcmp(a.id,b.id)<0;
}

int main()
{
    int n=0;
    int k;
    int num=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&k);
        for(int j=0;j<k;j++)
        {
        scanf("%s %d",stu[num].id,&stu[num].score);
        stu[num].room=i;
        num++;
        }
        sort(stu+num-k,stu+num,cmp);

        stu[num-k].rank=1;
        for(int j=num-k+1;j<num;j++)
        {
            if(stu[j].score==stu[j-1].score)
                stu[j].rank=stu[j-1].rank;
            else
                stu[j].rank=j+1-(num-k);
        }
    }
    sort(stu,stu+num,cmp);
    int r=1;
    for(int i=0;i<num;i++)
    {
        if(i>0 && stu[i].score!=stu[i-1].score){
            r=i+1;
        }
        printf("%s %d ",stu[i].id,stu[i].score);
        printf("%d %d %d\n",r,stu[i].room,stu[i].rank);
    }
}