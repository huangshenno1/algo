#include <cstdio>
#include <cmath>
#include <cstring>

const int maxn=1000001;

int gcd(int a,int b)
{
    return a%b==0?b:gcd(b,a%b);
}

int n,nn,ans1,ans2,u,v,x,y,z,xx,yy,zz,i;
bool used[maxn];

int main()
{
    while (~scanf("%d",&n))
    {
        memset(used,0,sizeof(used));
        ans1=ans2=0;
        nn=(int)sqrt((double)n);
        for (u=2;u<=nn;u++)
        {
            for (v=1;v<u;v++)
            {
                xx=u*u-v*v;
                yy=2*u*v;
                zz=u*u+v*v;
                if (zz>n)
                    break;
                if (gcd(xx,yy)==1)
                {
                    ans1++;
                    for (i=1;;i++)
                    {
                        x=xx*i;
                        y=yy*i;
                        z=zz*i;
                        if (z>n)
                            break;
                        used[x]=used[y]=used[z]=1;
                    }
                }
            }
        }
        for (i=1;i<=n;i++)
            if (!used[i])
                ans2++;
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}