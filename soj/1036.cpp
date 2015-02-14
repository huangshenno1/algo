#include <cstdio>

struct Node
{
    int no;
    Node *l,*r;
};
Node *node[20];
int n,a,b;

int main()
{
    Node *p1,*p2;
    int i;
    while (scanf("%d%d%d",&n,&a,&b)==3 && n)
    {
        for (i=0;i<n;i++) {node[i]=new Node; node[i]->no=i+1;}
        for (i=0;i<n-1;i++) node[i]->r=node[i+1]; node[n-1]->r=node[0];
        for (i=1;i<n;i++) node[i]->l=node[i-1]; node[0]->l=node[n-1];
        p1=node[n-1]; p2=node[0];
        while (n)
        {
            for (i=0;i<a;i++)
                p1=p1->r;
            for (i=0;i<b;i++)
                p2=p2->l;
            if (p1==p2)
            {
                printf("%3d",p1->no);
                (p1->l)->r=p1->r;
                (p1->r)->l=p1->l;
                p1=p1->l;
                p2=p2->r;
                n--;
            }
            else
            {
                printf("%3d",p1->no);
                (p1->l)->r=p1->r;
                (p1->r)->l=p1->l;
                p1=p1->l;

                printf("%3d",p2->no);
                (p2->l)->r=p2->r;
                (p2->r)->l=p2->l;
                p2=p2->r;

                n-=2;
            }
            if (n) printf(",");
        }
        printf("\n");
    }
    return 0;
}
