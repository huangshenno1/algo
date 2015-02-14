#include <cstdio>
#include <cstring>

typedef long long ll;
int T,i,j,k,l;
char str[25];
ll fac[25];
int cnt[26];
ll ans,t;

int main()
{
    fac[0]=1;
    for (i=1;i<=20;i++) fac[i]=fac[i-1]*i;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",str);
        l=strlen(str);
        memset(cnt,0,sizeof(cnt));
        for (i=0;i<l;i++) cnt[str[i]-'A']++;
        ans=0;
        for (i=0;i<l-1;i++)
        {
            for (j=0;'A'+j<str[i];j++)
            {
                if (cnt[j]>0)
                {
                    cnt[j]--;
                    t=fac[l-i-1];
                    for (k=0;k<26;k++)
                    {
                        if (cnt[k]>1)
                            t=t/fac[cnt[k]];
                    }
                    ans+=t;
                    cnt[j]++;
                }
            }
            cnt[str[i]-'A']--;
        }
        printf("%lld\n",ans);
    }
    return 0;
}