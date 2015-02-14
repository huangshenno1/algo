#include <stdio.h>
#define N 1000+10
int IsPrime(int n);
void main()
{
    int n,c,start,end,i,count;
    int prime[N];
    while (scanf("%d%d",&n,&c)==2)
    {
        i=1;
        count=0;
        printf("%d %d:",n,c);
        while (i<=n)
        {
            if (IsPrime(i))
                prime[count++]=i;
            i++;
        }
        if (((count%2==1)&&(2*c-1>=count))||((count%2==0)&&(2*c>=count)))
        {
            for (i=0;i<count;i++)
                printf(" %d",prime[i]);
        }
        else if (count%2==1)
        {
            start=(count+1)/2-c;
            end=(count-1)/2+c-1;
            for (i=start;i<=end;i++)
                printf(" %d",prime[i]);
        }
        else
        {
            start=count/2-c;
            end=count/2+c-1;
            for (i=start;i<=end;i++)
                printf(" %d",prime[i]);
        }
        putchar('\n');
        putchar('\n');
    }
}
int IsPrime(int n)
{
    int i;
    for (i=2;i*i<=n;i++)
        if (n%i==0)
            return 0;
    return 1;
}