#include <stdio.h>

int main()
{
    double a,b,c,d;
    while (scanf("%lf%lf%lf%lf",&a,&b,&c,&d)==4)
    {
        double max=0;
        int count;
        double temp;
        temp=a/c+b/d;
        if (temp>max)
        {
            max=temp;
            count=0;
        }
        temp=c/d+a/b;
        if (temp>max)
        {
            max=temp;
            count=1;
        }
        temp=d/b+c/a;
        if (temp>max)
        {
            max=temp;
            count=2;
        }
        temp=b/a+d/c;
        if (temp>max)
        {
            max=temp;
            count=3;
        }
        printf("%d\n",count);
    }
    return 0;
}