#include <cstdio>

int main()
{
    int h,m;
    while (scanf("%d%d",&h,&m)==2)
    {
        if (m>=45) m-=45;
        else
        {
            m=m+15;
            h=(h+23)%24;
        }
        printf("%d %d\n",h,m);
    }
    return 0;
}