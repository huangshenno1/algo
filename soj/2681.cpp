#include <cstdio>
#include <cstring>
#include <cmath>

bool isSquare(int x)
{
    int t=(int)sqrt((double)x);
    return t*t==x;
}

int main()
{
    int n;
    int top[1010],count;
    int i,j;
    bool flag;
    while (~scanf("%d",&n) && n)
    {
        memset(top,0,sizeof(top));
        count=0;
        for (i=1;i<=n;i++)
        {
            flag=0;
            for (j=0;j<count;j++)
            {
                if (isSquare(i+top[j]))
                {
                    top[j]=i;
                    flag=1;
                    break;
                }
            }
            if (!flag)
                top[count++]=i;
        }
        printf("%d\n",count);
    }
    return 0;
}