#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        char type[5];
        scanf("%d%s",&n,type);
        int last;
        scanf("%d",&last);
        int current;
        int compact=1;
        for (int i=1;i<n;i++)
        {
            scanf("%d",&current);
            if (current!=last)
            {
                compact++;
                last=current;
            }
        }
        int bit;
        if (type[0]=='i')
            bit=32;
        else bit=8;
        printf("%lf\n",((double)(n+compact*bit))/(n*bit));
    }
    return 0;
}