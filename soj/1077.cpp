#include <cstdio>
#include <set>
using namespace std;

const int maxn = 1000;
int n,m,count,i,j,k,a[10];
bool flag;
set<int> data[maxn][10];
set<int>::iterator it;


int main()
{
    while (scanf("%d",&n)==1)
    {
        for (i=0;i<n;i++)
        {
            for (j=0;j<10;j++)
                data[i][j].clear();
            scanf("%d",&k);
            while (k--)
            {
                scanf("%d",&j);
                data[i][j%10].insert(j);
            }
        }
        scanf("%d",&m);
        while (m--)
        {
            count=0;
            scanf("%d",&k);
            for (i=0;i<k;i++)
                scanf("%d",&a[i]);
            for (i=0;i<n;i++)
            {
                flag=1;
                for (j=0;j<k;j++)
                {
                    if ((it=data[i][a[j]%10].find(a[j])) == data[i][a[j]%10].end())
                    {
                        flag=0;
                        break;
                    }
                }
                if (flag)
                    count++;
            }
            printf("%d\n",count);
        }
    }
    return 0;
}