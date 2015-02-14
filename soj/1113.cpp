#include <stdio.h>
#include <string.h>

int main()
{
    int a[50];
    int b[50];
    int c[50];
    int t;
    int n,i,j;
    int temp;
    int count,line;
    int max,max_i;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (i=0;i<n;i++)
            scanf("%d",&a[i]);
        memset(b,0,sizeof(b));
        for (i=0;i<n;i++)
            b[i]=1;
        max=1;
        for (i=1;i<n;i++)
        {
            for (j=i-1;j>=0;j--)
            {
                if (a[i]<=a[j] && b[i]<=b[j])
                {
                    b[i]=b[j]+1;
                    c[i]=j;
                    if (b[i]>max)
                    {
                        max=b[i];
                        max_i=i;
                    }
                }
            }
        }
        line=1;
        count=n-max;
        while (b[max_i]!=1)
        {
            a[max_i]=-1;
            max_i=c[max_i];
        }
        a[max_i]=-1;
        while (count)
        {
            i=0;
            while (a[i]==-1)
                i++;
            temp=a[i];
            a[i]=-1;
            count--;
            line++;
            for (j=i+1;j<n;j++)
            {
                if (a[j]==-1)
                    continue;
                if (a[j]<=temp)
                {
                    temp=a[j];
                    a[j]=-1;
                    count--;
                }
            }
        }
        printf("%d %d\n",max,line);
    }
    return 0;
}