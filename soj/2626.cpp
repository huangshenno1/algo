#include <stdio.h>

int main()
{
    int iCase=0;
    int o,w;
    scanf("%d%d",&o,&w);
    while (o||w)
    {
        iCase++;
        int low=o/2,high=o*2;
        char cmd[3];
        int change;
        bool die=0;
        scanf("%s%d",cmd,&change);
        while (cmd[0]!='#')
        {
            if (cmd[0]=='F')
                w+=change;
            else w-=change;
            if (w<=0)
                die=1;
            scanf("%s%d",cmd,&change);
        }
        printf("%d ",iCase);
        if (die)
            printf("RIP\n");
        else if (w>low&&w<high)
            printf(":-)\n");
        else printf(":-(\n");
        scanf("%d%d",&o,&w);
    }
    return 0;
}