#include <cstdio>
#include <cstring>

const int maxn = 500010;
int n,k;
char in[maxn],ans[maxn];

int main()
{
    int i,j;
    while (scanf("%d%d",&n,&k)==2)
    {
        getchar();
        scanf("%s",in);
        
        j=0;
        for (i=0;i<n;i++)
        {
            while (j>0 && k>0 && ans[j-1]<in[i]) //删k个数
                j--,k--;
            ans[j++]=in[i];
        }
        ans[j]='\0';

        printf("%s\n",ans);
    }
    return 0;
}