#include <stdio.h>

struct Node
{
    int v,c;
    bool exist;
}node[100000];

int main()
{
    int t;
    int n;
    int sv,sc;
    int count;
    int i,j;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        sc=sv=0;
        count=n-1;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&node[i].v,&node[i].c);
            node[i].exist=1;
            sv+=node[i].v;
            sc+=node[i].c;
        }
        if (sv<sc)
        {
            printf("-1\n");
            continue;
        }
        i=-1;
        while (count)
        {
            i=(i+1)%n;
            while (!node[i].exist)
                i=(i+1)%n;
            if (node[i].v<node[i].c)
                continue;
            j=(i+1)%n;
            while (!node[j].exist)
                j=(j+1)%n;
            while (node[i].v+node[j].v>=node[i].c+node[j].c)
            {
                count--;
                if (!count)
                    break;
                node[i].v+=node[j].v;
                node[i].c+=node[j].c;
                node[j].exist=0;
                while (!node[j].exist)
                    j=(j+1)%n;
            }
        }
        printf("%d\n",i);
    }
    return 0;
}