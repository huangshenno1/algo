#include <cstdio>
#include <cstdlib>

struct F
{
    int a,b;
    double v;
}f[150000];
int count;
int t,n;

int GCD(int a,int b)
{
    return a%b?GCD(b,a%b):b;
}

int cmp(const void *a,const void *b)
{
    F *ta=(F*)a;
    F *tb=(F*)b;
    return (ta->v-tb->v>0)?1:-1;
}

int main()
{
    int i,j;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        count=0;
        for (j=2;j<=n;j++)
        {
            for (i=1;i<j;i++)
            {
                if (GCD(i,j)==1)
                {
                    f[count].a=i;
                    f[count].b=j;
                    f[count].v=(double)i/j;
                    count++;
                }
            }
        }
        qsort(f,count,sizeof(F),cmp);
        printf("%d/%d",f[0].a,f[0].b);
        for (i=1;i<count;i++)
            printf(",%d/%d",f[i].a,f[i].b);
        printf("\n");
    }
    return 0;
}