#include <stdio.h>
#include <math.h>
#include <string.h>

bool prime[1000001];

int main()
{
    unsigned int l,r;
    unsigned int i,j;
    unsigned int temp,rest;
    unsigned int d;
    unsigned int count;
    
    while (scanf("%u%u",&l,&r)==2)
    {
        memset(prime,0,sizeof(prime));
        d=r-l;
        temp=sqrt(r)+0.5;
        for (i=2;i<=temp;i++)
        {
            rest=(l-1)%i+1;
            j=i-rest;
            while (j<=d)
            {
                if (j+l!=i)
                    prime[j]=1;
                j+=i;
            }
        }
        count=0;
        for (i=0;i<=d;i++)
        {
            if (!prime[i])
                count++;
        }
        printf("%u\n",count);
    }
    return 0;
}