#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxn = 50010;
int T,n;
struct Node
{
    int k,m;
    bool operator<(const Node &o) const
    {
        return k<o.k;
    }
}box[maxn];
int mm,kk;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&box[i].k);
        for (int i=0;i<n;i++) scanf("%d",&box[i].m);
        sort(box,box+n);
        mm=box[n-1].m;
        for (int i=0;i<n-1;i++)
        {
            for (int j=box[i].k;j<box[i+1].k;j++) box[i].m=(int)ceil(box[i].m/8.0);
            if (box[i+1].m<box[i].m)
                box[i+1].m=box[i].m;
        }
        if (box[n-1].m==1) printf("%d\n",box[n-1].k);
        else
        {
            kk=box[n-1].k;
            mm=box[n-1].m;
            while (mm>1)
            {
                kk++;
                mm=(int)ceil(mm/8.0);
            }
            printf("%d\n",kk);
        }
    }
    return 0;
}