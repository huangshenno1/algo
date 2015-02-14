#include <stdio.h>
#include <math.h>
#include <string.h>

typedef struct
{
    double x,y;
    double r;
    int e;
}People;
People a[110];
int n;

double Distance(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
//    freopen("in.txt","r",stdin);
    double x,y,r2;
    int count;
    double d;
    int i,j;
    while (scanf("%d",&n)==1 && n)
    {
        scanf("%lf%lf%lf",&a[0].x,&a[0].y,&a[0].r);
        a[0].e=1;
        for (i=1;i<n;i++)
        {
            scanf("%lf%lf%lf",&a[i].x,&a[i].y,&a[i].r);
            a[i].e=1;
            count=0;
            while (count!=1)
            {
                x=a[i].x;
                y=a[i].y;
                r2=a[i].r*a[i].r;
                count=1;
                for (j=0;j<i;j++)
                {
                    if (a[j].e==0)
                        continue;
                    d=Distance(a[i].x,a[i].y,a[j].x,a[j].y);
                    if (d<=a[i].r||d<=a[j].r)
                    {
                        x+=a[j].x;
                        y+=a[j].y;
                        r2+=a[j].r*a[j].r;
                        a[j].e=0;
                        a[i].e++;
                        count++;
                    }
                }
                a[i].x=x/count;
                a[i].y=y/count;
                a[i].r=sqrt(r2);
            }
        }
        count=0;
        for (i=0;i<n;i++)
        {
            if (a[i].e)
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}