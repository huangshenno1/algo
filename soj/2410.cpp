#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,c,d,ans;
    while (scanf("%d%d%d%d",&a,&b,&c,&d)==4 && (a||b||c||d))
    {
        if (a<b) swap(a,b);
        if (c<d) swap(c,d);
        if (a<=c && b<=d) printf("100%%\n");
        else printf("%d%%\n",min(c*100/a,d*100/b));
    }
    return 0;
}
