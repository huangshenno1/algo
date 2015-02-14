#include <cstdio>

int main()
{
    long long a[4]={29,23,19,13},x[4],k[4];
    long long ans;
    while (scanf("%lld%lld%lld%lld",&x[0],&x[1],&x[2],&x[3])==4)
    {
        long long s=a[0]*a[1]*a[2]*a[3];
        for (int i=0;i<4;i++)
        {
            long long t=s/a[i];
            k[i]=t;
            while (k[i]%a[i]!=1)
                k[i]=(k[i]+t)%s;
        }
        ans=0;
        for (int i=0;i<4;i++)
            ans=(ans+(k[i]*x[i])%s)%s;
        if (ans==0) ans+=s;
        printf("%lld\n",ans);
    }
}