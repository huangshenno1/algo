#include <stdio.h>
#include <stdlib.h>

struct NODE
{
    int y,x;
}node[1000010];

int cmp(const void *a,const void *b)
{
    struct NODE *temp1=(struct NODE *)a;
    struct NODE *temp2=(struct NODE *)b;
    if (temp1->y==temp2->y)
        return temp1->x-temp2->x;
    return temp1->y-temp2->y;
}

char text[1010][1010];
    
int main()
{
//    freopen("in.txt","r",stdin);
    int n;
    int i,j,k;
    int temp;
    char c;
    while (scanf("%d",&n)==1 && n)
    {
        getchar();
        k=0;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                c=getchar();
                if (c=='O')
                {
                    node[k].y=i;
                    node[k].x=j;
                    k++;
                }
            }
            getchar();
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                text[i][j]=getchar();
            }
            getchar();
        }
        qsort(node,k,sizeof(struct NODE),cmp);
        for (i=0;i<k;i++)
            printf("%c",text[node[i].y][node[i].x]);
        for (j=0;j<3;j++)
        {
            for (i=0;i<k;i++)
            {
                temp=node[i].x;
                node[i].x=n-1-node[i].y;
                node[i].y=temp;
            }
            qsort(node,k,sizeof(struct NODE),cmp);
            for (i=0;i<k;i++)
                printf("%c",text[node[i].y][node[i].x]);
        }
        printf("\n");
    }
    return 0;
}