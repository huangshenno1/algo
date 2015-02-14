#include <stdio.h>

int stack[6][300001];
int top[6];

int main()
{
    int n,p;
    int s,f;
    int count;
    int i;
    while (scanf("%d%d",&n,&p)==2)
    {
        count=0;
        for (i=0;i<6;i++)
            top[i]=-1;
        while (n--)
        {
            scanf("%d%d",&s,&f);
            s--;
            if (top[s]==-1)
            {
                stack[s][++top[s]]=f;
                count++;
            }
            else
            {
                while (top[s]>=0 && stack[s][top[s]]>f)
                {
                    top[s]--;
                    count++;
                }
                if (top[s]==-1 || stack[s][top[s]]<f)
                {
                    stack[s][++top[s]]=f;
                    count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}