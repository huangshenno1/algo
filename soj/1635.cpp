#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int iCase=0;iCase<n;iCase++)
    {
        int a,b;
        int b0,b1,b2,b3;
        int l;
        int p0,p1,p2,p3;
        int p;
        scanf("%d%d",&a,&b);
        p=a*b;
        b0=b%10;
        p0=b0*a;
        b1=(b/10)%10;
        p1=b1*a;
        b2=(b/100)%10;
        p2=b2*a;
        b3=(b/1000);
        p3=b3*a;
        if (b3)
            l=4;
        else if (b2)
            l=3;
        else if (b1)
            l=2;
        else l=1;
        printf("%8d\nx%7d\n--------\n",a,b);
        if (l==4)
        {
            printf("%8d\n",p0);
            printf("%7d\n",p1);
            printf("%6d\n",p2);
            printf("%5d\n",p3);
        }
        if (l==3)
        {
            printf("%8d\n",p0);
            printf("%7d\n",p1);
            printf("%6d\n",p2);
        }
        if (l==2)
        {
            printf("%8d\n",p0);
            printf("%7d\n",p1);
        }
        if (l==1)
        {
            printf("%8d\n********************\n",p);
        }
        else printf("--------\n%8d\n********************\n",p);
    }
    return 0;
}