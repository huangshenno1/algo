#include<cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100005;

int n,t;
int p[N],dp[N];
vector<int> son[N];

int dfs(int x)
{
    if (dp[x]!=-1) return dp[x];
    if (son[x].size()==0) return dp[x]=1;
    dp[x]=0;
    vector<int> tmp;
    for (int i=0;i<son[x].size();i++)
        tmp.push_back(dfs(son[x][i]));
    sort(tmp.begin(),tmp.end());
    int cnt=(son[x].size()*t+99)/100;
    for (int i=0;i<cnt;i++)
        dp[x]+=tmp[i];
    return dp[x];
}

int main()
{
    p[0]=-1;
    while (scanf("%d%d",&n,&t)==2 && (n||t))
    {
        memset(dp,-1,sizeof(dp));
        for (int i=0;i<=n;i++) son[i].clear(); 
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&p[i]);
            son[p[i]].push_back(i);
        }        
        printf("%d\n",dfs(0));
    }    
    return 0;    
}