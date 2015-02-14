#include <stdio.h>
#include <math.h>

int main()
{
    int iCase=1;
    int a,b;
    int x;
    int temp;
    int count;
    while (scanf("%d%d",&a,&b)==2 &&(a||b))
    {
        count=0;
        for (x=sqrt((double)a+1);x<=sqrt((double)b);x++)
        {
            temp=sqrt(2.0*x*x);
            if (temp*temp+temp+2==2*x*x && x*x>a && x*x<b)
                count++;
        }
        printf("Case %d: %d\n",iCase++,count);
    }
    return 0;
}