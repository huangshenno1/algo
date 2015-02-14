#include <stdio.h>
#include <string.h>

int edge[300001];
int cmd[300001],x[300001];
int p[300001];
int s[300001];
bool v[300001],w[300001];

int Parent(int x)
{
    if (p[x]==x)
        return x;
    return p[x]=Parent(p[x]);
}

int main()
{
    int n,q;
    int i,temp,temp2;
    while (scanf("%d",&n)==1)
    {
        memset(v,0,sizeof(v));
        memset(w,0,sizeof(w));
        for (i=1;i<=n;i++)
        {
            p[i]=i;
            scanf("%d",&edge[i]);
        }
        scanf("%d",&q);
        for (i=1;i<=q;i++)
        {
            scanf("%d%d",&cmd[i],&x[i]);
            if (cmd[i]==2)
                v[x[i]]=1;
        }
        for (i=1;i<=n;i++)
        {
            if (!v[i]&&edge[i])
            {
                if (Parent(i)!=Parent(edge[i]))
                    p[Parent(i)]=edge[i];
                else w[Parent(edge[i])]=1;
            }
        }
        for (i=q;i>=1;i--)
        {
            if (cmd[i]==1)
            {
                temp=x[i];
                if (w[Parent(temp)]==1)
                    s[i]=-1;
                else s[i]=Parent(temp);
            }
            else
            {
                temp=x[i];
                temp2=edge[temp];
                if (Parent(temp)==Parent(temp2))
                    w[Parent(temp)]=1;
                else p[Parent(temp)]=temp2;
            }
        }
        for (i=1;i<=q;i++)
        {
            if (cmd[i]==1)
            {
                if (s[i]==-1)
                    printf("CIKLUS\n");
                else printf("%d\n",s[i]);
            }
        }
    }
    return 0;
}