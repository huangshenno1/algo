#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        bool flag=0;
        int dog,cat,turtle;
        int s,p,y,j;
        scanf("%d%d%d%d",&s,&p,&y,&j);
        int small=(j+12-p-y-2)/3;
        for (turtle=small;;turtle++)
        {
            for (cat=turtle+p-1;cat<=turtle+p+1;cat++)
            {
                for (dog=cat+s-1;dog<=cat+s+1&&dog<=turtle+y+1;dog++)
                {
                    if (dog+cat+turtle==j+12)
                    {
                        printf("%d %d %d\n",dog,cat,turtle);
                        flag=1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
            if (flag)
                break;
        }
    }
    return 0;
}