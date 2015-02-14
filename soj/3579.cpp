#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > q;
int T,n,m,i,t;
int a[100010];

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        if (n<m)
        {
            printf("0\n");
            continue;
        }
        while (!q.empty())
            q.pop();
        for (i=0;i<m;i++)
            q.push(a[i]);
        while (1)
        {
            t=q.top();
            if (t>600)
            {
                t=-1;
                break;
            }
            if (i>=n)
                break;
            q.pop();
            q.push(t+a[i]);
            i++;
        }
        printf("%d\n",t);
    }
    return 0;
}