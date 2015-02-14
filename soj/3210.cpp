#include <stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        scanf("%d",&n);
        int win_a=0,win_b=0;
        char a[2],b[2];
        for (int i=0;i<n;i++)
        {
            scanf("%s%s",a,b);
            if (a[0]=='R'&&b[0]=='S')
                win_a++;
            if (a[0]=='S'&&b[0]=='P')
                win_a++;
            if (a[0]=='P'&&b[0]=='R')
                win_a++;
            if (b[0]=='R'&&a[0]=='S')
                win_b++;
            if (b[0]=='S'&&a[0]=='P')
                win_b++;
            if (b[0]=='P'&&a[0]=='R')
                win_b++;
        }
        if (win_a>win_b)
            printf("Player 1\n");
        else if (win_b>win_a)
            printf("Player 2\n");
        else printf("TIE\n");
    }
    return 0;
}