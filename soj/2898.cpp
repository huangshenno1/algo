#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    scanf("%d",&n);
    while (n)
    {
        char s[210];
        scanf("%s",s);
        int l=strlen(s);
        int k=0;
        int m=l/n;
        char decrypt[210][210];
        for (int i=0;i<m;i++)
        {
            if (i%2)
            {
                for (int j=n-1;j>=0;j--)
                {
                    decrypt[i][j]=s[k++];
                }
            }
            else
            {
                for (int j=0;j<n;j++)
                {
                    decrypt[i][j]=s[k++];
                }
            }
        }
        for (int j=0;j<n;j++)
        {
            for (int i=0;i<m;i++)
            {
                printf("%c",decrypt[i][j]);
            }
        }
        printf("\n");
        scanf("%d",&n);
    }
    return 0;
}