#include <cstdio>

int powc[35];
int c,n;
int a,b,ans;

void init() {powc[0]=1; for (int i=1;i<=n;i++) powc[i]=powc[i-1]*c;}
int gcd(int a,int b) {return b==0 ? a:gcd(b,a%b);}

int main()
{
    while (scanf("%d%d",&c,&n)==2 && (c||n))
    {
        init();
        
        a=0;
        for (int i=1;i<=n;i++)
            a += powc[gcd(i,n)];
        b=0;
        if (n&1) b = n*powc[(n+1)/2];
        else b = n/2*(powc[n/2+1]+powc[n/2]);

        ans = (a+b)/2/n;
        printf("%d\n",ans);
    }
    return 0;
}