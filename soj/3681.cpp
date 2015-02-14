#include <cstdio>

const int maxn = 80010;

int n;
int top[maxn],pre[maxn];

int main()
{
    int id;
    char cmd[3];
    while (scanf("%d",&n)==1)
    {
        top[0]=-1;
        for (int i=1;i<=n;i++)
        {
            scanf("%s",cmd);
            if (cmd[0]!='s') scanf("%d",&id);

            if (cmd[0]=='a')
            {
                top[i]=id;
                pre[i]=i-1;
            }
            if (cmd[0]=='s')
            {
                top[i]=top[pre[i-1]];
                pre[i]=pre[pre[i-1]];
            }
            if (cmd[0]=='t')
            {
                top[i]=top[id-1];
                pre[i]=pre[id-1];
            }
            printf("%d\n",top[i]);
        }
    }
    return 0;
}