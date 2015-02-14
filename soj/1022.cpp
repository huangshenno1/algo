#include <stdio.h>
int isrp(int a,int b)
{
    int t=1;
    if (a==b)
        return 0;
    if (a<b)
    {
        t=a;
        a=b;
        b=t;
    }
    while (t)
    {
        t=a%b;
        a=b;
        b=t;
    }
    if (a>1)
        return 0;
    else return 1;
}
void main()
{
    int step,mod;
    while (scanf("%d%d",&step,&mod)==2)
    {
        if (isrp(step,mod))
            printf("%10d%10d    Good Choice\n",step,mod);
        else printf("%10d%10d    Bad Choice\n",step,mod);
        putchar('\n');
    }
}