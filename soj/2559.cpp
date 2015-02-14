#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 45005;
int n;
int a[maxn],b[maxn],c[maxn];
map<int,int> dic;

int lowbit(int x) {return x&-x;}

void add(int x, int d)
{
    while (x <= n)
    {
        c[x] += d;
        x += lowbit(x);
    }    
}

int sum(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret += c[x];
        x -= lowbit(x);
    }
    return ret;
}

int main()
{
    while (scanf("%d",&n)==1)
    {
        for (int i=0;i<n;i++) {scanf("%d",&a[i]); b[i]=-a[i];}
        sort(b,b+n);
        dic.clear();
        for (int i=0;i<n;i++) dic[-b[i]]=i+1;
        memset(c,0,sizeof(c));
        for (int i=0;i<n;i++)
        {
            printf("%d\n",sum(dic[a[i]])+1);
            add(dic[a[i]],1);
        }
    }
    return 0;
}