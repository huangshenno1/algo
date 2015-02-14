#include <cstdio>
#include <cstring>
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

int cas=1;
int n[8],sum;

int main()
{
    while (scanf("%d%d%d%d%d%d",&n[1],&n[2],&n[3],&n[4],&n[5],&n[6])==6 && (n[1]||n[2]||n[3]||n[4]||n[5]||n[6]))
    {
        sum=0;
        for (int v=1;v<=6;v++)
            sum+=v*n[v];
        if (sum&1)
        {
            printf("Collection #%d:\n",cas++);
            puts("Can't be divided.\n");
            continue;
        }
        if (n[1]>=6)
        {
            printf("Collection #%d:\n",cas++);
            puts("Can be divided.\n");
            continue;
        }
        for (int i=1;i<=6;i++)
        {
            if (n[i]%2==0 && n[i]>6) n[i]=6;
            else if (n[i]%2==1 && n[i]>7) n[i]=7;
        }
        bool flag=0;
        for (int i=0;i<=n[6];i++)
        {
            if (i*6>sum/2) break;
            for (int j=0;j<=n[5];j++)
            {
                for (int k=0;k<=n[4];k++)
                {
                    for (int l=0;l<=n[3];l++)
                    {
                        for (int p=0;p<=n[2];p++)
                        {
                            int tmp=i*6+j*5+k*4+l*3+p*2;
                            if (tmp<=sum/2 && tmp+n[1]>=sum/2) {flag=1; break;}
                        }
                        if (flag) break;
                    }
                    if (flag) break;
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag)
        {
            printf("Collection #%d:\n",cas++);
            puts("Can be divided.\n");
        }
        else
        {
            printf("Collection #%d:\n",cas++);
            puts("Can't be divided.\n");
        }
    }
    return 0;
}
