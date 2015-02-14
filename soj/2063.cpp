#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int iCase=0;iCase<n;iCase++)
    {
        long long k;
        scanf("%lld",&k);
        int hex[4];
        for (int i=0;i<4;i++)
        {
            hex[i]=k%256;
            k=k/256;
            printf("0x%02X",hex[i]);
            if (i<3)
                printf(" ");
            else printf("\n");
        }
    }
    return 0;
}