#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

int T,n;
int a[101],b[101];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        a[0]=-1000;

        for (int i=1,j;i<n;i++)
        {
            if (!(a[i]!=a[i-1]+1 && a[i]+1<a[n]))
            {
                for (j=i+1;a[i]==a[j];j++);
                if (j<=n) swap(a[i],a[j]);
            }
            b[i]=a[i];
        }
        b[n]=a[n];

        for (int i=1;i<n;i++) printf("%d ",b[i]);
        printf("%d\n",b[n]);
    }
    return 0;
}
