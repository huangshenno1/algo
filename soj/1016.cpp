#include <cstdio>

bool flag;
int ans,tree[1000],exist[1000];
void solve(int i,int s)
{
    if (exist[i*2]==-1&&exist[i*2+1]==-1)
    {
        if (s==ans)
            flag=1;
        return;
    }
    if (exist[i*2]==1)
        solve(i*2,s+tree[i*2]);
    if (exist[i*2+1]==1)
        solve(i*2+1,s+tree[i*2+1]);
}

int main()
{
    int sum,v,idx;
    char c;
    while (scanf("%d",&ans)==1)
    {
        getchar();
        getchar();
        for (int i=0;i<1000;i++) exist[i]=0;
        idx=1;
        exist[idx]=-1;
        c=getchar();
        while (idx!=0)
        {
            if (c==' '||c=='\n') c=getchar();
            else if (c=='(')
            {
                if (exist[idx*2]) idx=idx*2+1;
                else idx=idx*2;
                exist[idx]=-1;
                c=getchar();
            }
            else if (c==')')
            {
                idx=idx/2;
                c=getchar();
            }
            else
            {
                v=0;
                flag=0;
                if (c=='-')
                {
                    flag=1;
                    c=getchar();
                }
                while (c>='0'&&c<='9')
                {
                    v=v*10+c-'0';
                    c=getchar();
                }
                if (flag) v=-v;
                tree[idx]=v;
                exist[idx]=1;
            }
        }
        if (exist[1]==-1)
        {
            puts("no");
            continue;
        }
        idx=1;
        sum=tree[idx];
        flag=0;
        solve(idx,sum);
        if (flag) puts("yes");
        else puts("no");
    }
    return 0;
}