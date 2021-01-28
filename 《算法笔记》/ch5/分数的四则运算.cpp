#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Frac{
    int up,down;
} f1;

int gcd(int a, int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}

Frac Reduction(Frac result){
    if(result.down<0)
    {
        result.up*=-1;
        result.down*=-1;
    }
    if(result.up==0)
    {
        result.down=1;
    }
    else{
        int d=gcd(result.down,result.down);
        result.down/=d;
        result.up/=d;
    }
    return result;
}

Frac Add(Frac f1, Frac f2)
{
    Frac r;
    r.up=f1.up*f2.down+f2.down*f1.down;
    r.down=f1.down*f2.down;
    return Reduction(r);
}

Frac Sub(Frac f1, Frac f2)
{
    Frac r;
    r.up=f1.up*f2.down-f2.down*f1.down;
    r.down=f1.down*f2.down;
    return Reduction(r);
}

Frac Multi(Frac f1, Frac f2)
{
    Frac r;
    r.up=f1.up*f2.up;
    r.down=f1.down*f2.down;
    return Reduction(r);
}

Frac Fraction(Frac f1, Frac f2)
{
    Frac r;
    r.up=f1.up*f2.down;
    r.down=f1.down*f2.up;
    return Reduction(r);
}

void showFrac(Frac f)
{
    //考虑的情况：
    //分母为1 
    //假分数
    printf("%d/%d\n",f.up,f.down);
    f=Reduction(f);
    if(f.down==1)
    {
        printf("%d\n",f.up);
    }
    else if(abs(f.up)>abs(f.down))
    {
        printf("%d %d/%d\n",f.up/f.down,f.up%f.down,f.down);
    }
    else
    {
        printf("%d/%d\n",f.up,f.down);
    }
}

int main()
{
    f1.up=140;
    f1.down=2;
    showFrac(f1);
    return 0;
}
