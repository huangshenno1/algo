#include<stdio.h>
#include<string.h>
int front1,front2,rear1,rear2;
int  a[1100010];
int q1[1100010];
int q2[1100010];
int an[1100010];

int main()
{
    int n,m,i;
    while (scanf("%d%d",&n,&m)==2)
    {
        front1=1,front2=1,rear1=1,rear2=1;
        if(m==1)
        {
            for(i=0;i<n;i++)
            {
                scanf("%d",&a[i]);
                printf("%d ",a[i]);
            }
            printf("\n");
            for(i=0;i<n;i++)
                printf("%d ",a[i]);
            printf("\n");
        }
        else
        {
            scanf("%d",&a[1]);
            q1[1]=q2[1]=1;
            for(i=2;i<m;i++)
            {
                scanf("%d",&a[i]);
                while (a[q1[rear1]]>=a[i]&&front1<=rear1)
                    rear1--;
                q1[++rear1]=i;
                while (a[q2[rear2]]<=a[i]&&front2<=rear2)
                    rear2--;
                q2[++rear2]=i;
            }
            for(i=m;i<=n;i++)
            {
                scanf("%d",&a[i]);
                while(a[q1[rear1]]>=a[i]&&front1<=rear1)
                    rear1--;
                q1[++rear1]=i;
                printf("%d ",a[q1[front1]]);
                if(q1[front1]==i-m+1)
                    front1++;
                while(a[q2[rear2]]<=a[i]&&front2<=rear2)
                    rear2--;
                q2[++rear2]=i;
                an[i]=a[q2[front2]];
                if(q2[front2]==i-m+1)
                    front2++;
            }
            printf("\n");
            for    (i=m;i<=n;i++)
                printf("%d ",an[i]);
            printf("\n");
        }
    }
    return 0;
}