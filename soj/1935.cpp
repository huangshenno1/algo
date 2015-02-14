#include<cstdio>  
#define min(a,b) (a<b?a:b)  
using namespace std;  
const int mm=2222222;  
const int mn=11111;  
int t[mm],p[mm];  
int h[mn],num[mn],dfn[mn],low[mn];  
int i,j,k,rt,n,m,top,idn,cnt,sum,ans;  
void dfs(int u,int fa)  
{  
    int i,v,cnt=0;  
    dfn[u]=low[u]=++idn;  
    for(i=h[u];i>=0;i=p[i])  
        if(!dfn[v=t[i]])  
        {  
            dfs(v,u);  
            ++cnt;  
            low[u]=min(low[u],low[v]);  
            if((u==rt&&cnt>1)||(u!=rt&&dfn[u]<=low[v]))++num[u];  
        }  
        else if(v!=fa)low[u]=min(low[u],dfn[v]);  
}  
void tarjan()  
{  
    for(top=idn=cnt=rt=0;rt<n;++rt)dfn[rt]=num[rt]=0;  
    for(sum=ans=rt=0;rt<n;++rt)  
    {  
        if(!dfn[rt])dfs(rt,0),++sum;  
        if(num[rt]>ans)ans=num[rt];  
    }  
    ans+=sum;  
}  
int main()  
{  
    while(scanf("%d%d",&n,&m),n+m)  
    {  
        if(m==0)  
        {  
            printf("%d\n",n-1);  
            continue;  
        }  
        for(k=i=0;i<n;++i)h[i]=-1;  
        while(m--)  
        {  
            scanf("%d%d",&i,&j);  
            t[k]=j,p[k]=h[i],h[i]=k++;  
            t[k]=i,p[k]=h[j],h[j]=k++;  
        }  
        tarjan();  
        printf("%d\n",ans);  
    }  
    return 0;  
}  