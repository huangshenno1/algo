#include <cstdio>
#include <cstring>

int n;
char ans[15010],mn[15010];

int main()
{
    int t,i;
    while (~scanf("%d %s",&n,mn))
    {
        t=1;
        while (t<n)
            t=t*10+1;
        i=0;
        while (1)
        {
            ans[i++]=t/n+'0';
            t=t%n;
            if (t==0) break;
            t=t*10+1;
        }
        ans[i]='\0';
        if (strcmp(ans,mn)==0)
            printf("%d Yes\n",n);
        else printf("%d No %s\n",n,ans);
    }
    return 0;
}