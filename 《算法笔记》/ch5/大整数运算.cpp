#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

struct bign{
    int d[1000];
    int len;

    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }

};

bign change(char str[]){
    bign a;
    a.len=strlen(str);
    for(int i=0;i<a.len;i++)
    {
        a.d[i]=str[a.len-i-1]-'0';
    }
    return a;
}

bool compare(bign a, bign b)
{
    if(a.len>b.len)
        return 1;
    else if(a.len<b.len)
        return -1;
    else
    {
        for(int i=a.len-1;i>=0;i--)
        {
            if(a.d[i]>b.d[i]) return 1;
            else if(a.d[i]<b.d[i])
            return -1;
        }
        return 0;
    }
}

bign add(bign a,bign b)
{
    bign c;
    int carry=0;//进位
    for(int i=0;i<a.len || i<b.len;i++)
    {
        int temp=a.d[i]+b.d[i]+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;
    }
    if(carry!=0)
    {
        c.d[c.len++]=carry;
    }
    return c;
}

bign myadd(bign a,bign b)
{
    bign c;
    int carry=0;
    for(int i=0;i<a.len || i<b.len;i++)
    {
        int temp=a.d[i]+b.d[i]+carry;
        c.d[c.len++]=temp%10;
        carry=temp/10;  
    }
    if(carry!=0)
    {
        c.d[c.len++]=carry;
    }
    return c;
}



bign sub(bign a, bign b)
{
    bign c;
    for(int i=0;i<a.len || i<b.len;i++)
    {
        if(a.d[i]<b.d[i])
        {
            a.d[i+1]--;//借位
            a.d[i]+=10;
        }
        c.d[c.len++]=a.d[i]-b.d[i];
    }
    return c;
}


int main()
{
    bign a,b;
    int aa[]={1,2,3,4,5,6,7};
    int bb[]={5,4,5,5,5,5,5,4,4,1};
    for(int i=0;i<7;i++)
    {    
        a.d[i]=aa[6-i];
    }
    a.len=7;
    for(int i=0;i<10;i++)
    {
        b.d[i]=bb[9-i];
    }
    b.len=10;
    a=myadd(a,b);
    for(int i=0;i<a.len;i++)
    {
        printf("%d",a.d[a.len-1-i]);
    }
    printf("\n");
    return 0;
}
