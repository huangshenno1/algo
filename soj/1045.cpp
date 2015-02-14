#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int stick[100],sum,ans;
bool used[100];

bool cmp(int a,int b)
{
    return a>b;
}

bool dfs(int k,int l,int r)
{
    if (l==r) return 1;
    for (int i=k;i<n;i++)
    {
        if (used[i] || stick[i]>l) continue;
        used[i]=1;
        if (stick[i]==l) {if (dfs(0,ans,r-stick[i])) return 1;}
        else if (dfs(i+1,l-stick[i],r-stick[i])) return 1;
        used[i]=0;
        if (stick[i]==l) return 0;
        if (r==sum) return 0;
        if (l==ans) return 0;
        while (stick[i+1]==stick[i]) i++;
    }
    return 0;
}

int main()
{
    while (scanf("%d",&n)==1 && n)
    {
        sum=0;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&stick[i]);
            sum+=stick[i];
            used[i]=0;
        }
        sort(stick,stick+n,cmp);
        ans=stick[0];
        while (sum%ans) ans++;
        while (!dfs(0,ans,sum))
        {
            ans++;
            while (sum%ans) ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}