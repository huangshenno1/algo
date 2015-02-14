#include <stdio.h> 
#include <string.h>
#include <vector>  
using namespace std;

#define MAX 50005  

vector <int> edge[MAX];  
int dp[MAX][2];  
int vis[MAX];  

int Max(int x,int y)  
{  
    return x>y?x:y;  
}  

void Solve(int t)  
{  
    int i,j,k;  
    vis[t]=1;  
    dp[t][1]=1;  
    for (i=0;i<edge[t].size();i++)  
    {  
        k=edge[t][i];  
        if (vis[k]==0)   
        {  
            Solve(k);  
            dp[t][0]+=Max(dp[k][0],dp[k][1]);  
            dp[t][1]+=dp[k][0];  
        }   
    }  
}  
int main()  
{
    int i,j,n,x,y;  
    while (scanf("%d",&n)==1)
    {
        memset(vis,0,sizeof(vis));
        memset(dp,0,sizeof(dp));
        for (i=0;i<MAX;i++)
            edge[i].clear();
        for (i=1;i<n;i++)  
        {  
            scanf("%d%d",&x,&y);  
            x--;  
            y--;  
            edge[x].push_back(y);  
            edge[y].push_back(x);  
        }  
        Solve(0);  
        printf("%d\n",Max(dp[0][0],dp[0][1])); 
    }
    return 0;  
}  