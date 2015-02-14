#include <stdio.h>

void Swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}

int main()
{
    int a,b,c,x,y;
    while (scanf("%d%d%d%d%d",&a,&b,&c,&x,&y)&&(x||y||a||b||c))
    {
        if (a<b)
            Swap(a,b);
        if (b<c)
            Swap(b,c);
        if (a<b)
            Swap(a,b);
        if (x<y)
            Swap(x,y);
        if (a>x&&b>y)
        {
            printf("-1\n");
            continue;
        }
        if (y<b)
        {
            a++;
            if (a==x)
                a++;
            if (a>52)
            {
                printf("-1\n");
                continue;
            }
            printf("%d\n",a);
            continue;
        }
        if (y>a)
        {
            int t=1;
            while (t==c||t==b||t==a||t==x||t==y)
                t++;
            printf("%d\n",t);
            continue;
        }
        b++;
        while (a==b||x==b||y==b)
            b++;
        if (b>52)
        {
            printf("-1\n");
            continue;
        }
        printf("%d\n",b);
    }
    return 0;
}