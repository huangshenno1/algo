#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int S=27,H=27,C=27,D=27;
        int n;
        scanf("%d",&n);
        char temp[5];
        for (int i=0;i<n;i++)
        {
            scanf("%s",temp);
            switch (temp[0])
            {
            case 'S':
                S--;
                break;
            case 'H':
                H--;
                break;
            case 'C':
                C--;
                break;
            case 'D':
                D--;
                break;
            default:
                break;
            }
        }
        printf("%lf\n",(double)H/(S+H+C+D));
    }
    return 0;
}