#include <stdio.h>
#include <string.h>

bool Exist(char num[],char ch)
{
    for (int i=0;num[i]!='\0';i++)
    {
        if (num[i]==ch)
            return 1;
    }
    return 0;
}

int main()
{
    long long a[1100];
    int n;
    int i,j;
    char num[20];
    char ch;
    long long ans;
    int temp;
    while (scanf("%d",&n)==1)
    {
        memset(a,0,sizeof(a));
        for (i=0;i<n;i++)
        {
            temp=0;
            scanf("%s",num);
            for (ch='0';ch<='9';ch++)
            {
                if (Exist(num,ch))
                    temp=temp<<1|1;
                else temp=temp<<1;
            }
            a[temp]++;
        }
        ans=0;
        for (i=0;i<1024;i++)
        {
            for (j=i+1;j<1024;j++)
            {
                if (i&j)
                    ans+=a[i]*a[j];
            }
            ans+=a[i]*(a[i]-1)/2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}