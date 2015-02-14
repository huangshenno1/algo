#include <stdio.h>

int main()
{
    int n;
    while (scanf("%d",&n)==1)
    {
        bool flag=1;
        if (n==1)
        {
            for (int i=2;i<9;i++)
            {
                scanf("%d",&n);
                if (n!=i)
                    flag=0;
            }
            if (flag)
                printf("ascending\n");
            else printf("mixed\n");
        }
        else if (n==8)
        {
            for (int i=7;i>0;i--)
            {
                scanf("%d",&n);
                if (n!=i)
                    flag=0;
            }
            if (flag)
                printf("descending\n");
            else printf("mixed\n");
        }
        else printf("mixed\n");
    }
    return 0;
}