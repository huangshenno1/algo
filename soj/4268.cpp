#include <cstdio>
#include <cmath>

int T,x1,x2,x3,yy1,y2,y3;
int up,down,left,right;

double f(int a1,int b1,int a2,int b2)
{
    double t=a1*a2+b1*b2;
    double tt=t/(sqrt(a1*a1+b1*b1+0.0)*sqrt(a2*a2+b2*b2+0.0));
    return acos(tt);
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d%d%d%d",&x1,&yy1,&x2,&y2,&x3,&y3);
        if (x1>x2)
        {
            if (yy1>y2)
            {
                up=y2; down=up-50;
                right=x2; left=right-50;
            }
            else
            {
                down=y2; up=down+50;
                right=x2; left=right-50;
            }
        }
        else
        {
            if (yy1>y2)
            {
                up=y2; down=up-50;
                left=x2; right=left+50;
            }
            else
            {
                down=y2; up=down+50;
                left=x2; right=left+50;
            }
        }
        if (x3<left || x3>right || y3<down || y3>up || f(x1-x2,yy1-y2,x2-x3,y2-y3) > acos(-1.0)*25.0/180.0)
        {
            puts("NO");
            continue;
        }
        puts("YES");
    }
    return 0; 
}