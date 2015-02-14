#include <stdio.h>

int C(int n,int m)
{
    if (m==0)
        return 1;
    if (n-m<m)
        m=n-m;
    int ans=1;
    int i;
    for (i=0;i<m;i++)
        ans*=n-i;
    for (i=1;i<=m;i++)
        ans/=i;
    return ans;
}

int main()
{
    char str[10];
    int num[10];
    int ans;
    int i,j,l;
    bool flag;
    while (scanf("%s",str)==1)
    {
        flag=1;
        ans=1;
        l=1;
        num[0]=str[0]-'a'+1;
        for (i=1;str[i]!='\0';i++)
        {
            num[i]=str[i]-'a'+1;
            if (num[i]<=num[i-1])
            {
                printf("0\n");
                flag=0;
                break;
            }
            l++;
        }
        if (!flag)
            continue;
        for (i=1;i<l;i++)
            ans+=C(26,i);
        for (i=0;i<l;i++)
        {
            for (j=(i==0?1:num[i-1]+1);j<num[i];j++)
            {
                ans+=C(26-j,l-i-1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}