#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn=100;
int n,ans,aa,bb;
int a[maxn],b[maxn],len;

void f(int ta,int tb,int i)
{
    if (i>=len)
        return;
    if (ta+tb<=ans)
        return;
    if (ta>=0 && tb>=0 && ta+tb>ans)
        ans=ta+tb;
    f(ta,tb,i+1);
    f(ta+a[i],tb+b[i],i+1);
}

int main()
{
    int ta,tb;
    int i;
    while (scanf("%d",&n)==1)
    {
        ans=ta=tb=len=0;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&aa,&bb);
            if (aa>=0 && bb>=0)
            {
                ta+=aa;
                tb+=bb;
                ans+=aa+bb;
            }
            else if (aa*bb<=0 && aa+bb>=0)
            {
                a[len]=-aa;
                b[len]=-bb;
                ta+=aa;
                tb+=bb;
                len++;
            }
        }
        f(ta,tb,0);
        printf("%d\n",ans);
    }
    return 0;
}