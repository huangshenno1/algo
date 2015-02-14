#include <stdio.h>

int main()
{
    int a,b;
    while (scanf("%d%d",&a,&b)==2)
    {
        int t1=a%10,t2=a/100;
        a=a-t1+t2-t2*100+t1*100;
        t1=b%10,t2=b/100;
        b=b-t1+t2-t2*100+t1*100;
        printf("%d\n",a>b?a:b);
    }
    return 0;
}