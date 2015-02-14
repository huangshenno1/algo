#include <stdio.h>

int main()
{
    int n,k;
    int i;
    char a[30];
    int b[101];
    char c[101];
    bool alphabet[30];
    int go;
    bool flag;
    while (scanf("%d%d",&n,&k)==2)
    {
        flag=0;
        for (i=0;i<n;i++)
            a[i]='?';
        for (i=0;i<26;i++)
            alphabet[i]=0;
        for (i=0;i<k;i++)
            scanf("%d %c",&b[i],&c[i]);
        a[0]=c[k-1];
        alphabet[a[0]-'A']=1;
        go=0;
        for (i=k-1;i>0;i--)
        {
            go=(go+b[i])%n;
            if (a[go]=='?')
            {
                a[go]=c[i-1];
                if (alphabet[a[go]-'A']==1)
                {
                    flag=1;
                    break;
                }
                alphabet[a[go]-'A']=1;
            }
            else if (a[go]!=c[i-1])
            {
                flag=1;
                break;
            }
        }
        if (flag)
        {
            printf("!\n");
            continue;
        }
        for (i=0;i<n;i++)
            printf("%c",a[i]);
        printf("\n");
    }
    return 0;
}