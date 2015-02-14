#include <stdio.h>
#include <string.h>

int main()
{
    int T,t;
    scanf("%d",&T);
    for (t=0;t<T;t++)
    {
        char n[1000010];
        scanf("%s",n);
        int l=strlen(n);
        bool minus=0;
        int i=0;
        int ans=0;
        if (n[0]=='-')
        {
            minus=1;
            i++;
        }
        for (;i<l;i++)
        {
            ans=(ans+n[i]-'0')%9;
        }
        if (minus)
        {
            ans=(9-ans)%9;
        }
        printf("%d\n",ans);
    }
    return 0;
}