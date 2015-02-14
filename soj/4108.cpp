#include <stdio.h>

int minimum(int a,int b)
{
    if (a<b)
        return a;
    else return b;
}
int maximum(int a,int b)
{
    if (a<b)
        return b;
    else return a;
}
int abs(int a)
{
    if (a<0)
        a=-a;
    return a;
}
int main()
{
    int t,k;
    int n;
    int min,max,tempmax;
    int delv,delh;
    int countE,countW,countN,countS,countQ;
    char c;

    scanf("%d",&t);
    for (k=0;k<t;k++)
    {
        scanf("%d",&n);
        max=0;
        countE=countW=countN=countS=countQ=0;
        scanf("%c",&c);
        scanf("%c",&c);
        while (c!='\n')
        {
            if (c=='W')
            {
                countW++;
            }
            if (c=='E')
            {
                countE++;
            }
            if (c=='N')
            {
                countN++;
            }
            if (c=='S')
            {
                countS++;
            }
            if (c=='?')
            {
                countQ++;
            }
            delv=abs(countN-countS);
            delh=abs(countW-countE);
            tempmax=maximum(delv,delh)+countQ;
            if (tempmax>max)
                max=tempmax;
            scanf("%c",&c);
        }
        min=n/2-max;
        if (min<0)
        {
            min=0;
        }
        printf("%d\n",min);
    }
    return 0;
}