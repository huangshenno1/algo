#include <stdio.h>

typedef struct
{
    int x,y;
    int d;
}Node;

int t,n,step,i;
Node bullet[20];
Node plane;
bool flag;

bool Crash()
{
    for (i=0;i<n;i++)
    {
        if (plane.x==bullet[i].x && plane.y==bullet[i].y)
            return 1;
    }
    return 0;
}

void Go()
{
    if (plane.d==1)
    {
        plane.x--;
        if (plane.x<0)
            plane.x=n-1;
    }
    if (plane.d==2)
    {
        plane.x++;
        if (plane.x>=n)
            plane.x=0;
    }
    for (i=0;i<n;i++)
    {
        if (bullet[i].d==1)
        {
            bullet[i].y--;
            if (bullet[i].y<0)
                bullet[i].y=n-1;
        }
        if (bullet[i].d==2)
        {
            bullet[i].y++;
            if (bullet[i].y>=n)
                bullet[i].y=0;
        }
    }
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        step=0;
        flag=0;
        scanf("%d",&n);
        for (i=0;i<n;i++)
        {
            bullet[i].x=i;
            scanf("%d",&bullet[i].y);
            scanf("%d",&bullet[i].d);
        }
        scanf("%d%d%d",&plane.x,&plane.y,&plane.d);
        while (step<n)
        {
            if (Crash())
            {
                flag=1;
                break;
            }
            Go();
            step++;
        }
        if (flag)
            printf("Are you blind or something? You got shot after %d step(s).\n",step);
        else printf("I don't look like a ghost, do I?\n");
    }
    return 0;
}