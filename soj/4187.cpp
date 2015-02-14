#include <stdio.h>
#include <string.h>

char str[1000000];
int num[110];
long long s[110][110];
bool vis[110][110];
bool op[110];
int n;

long long Max(long long a,long long b)
{
    return a>b?a:b;
}

long long Min(long long a,long long b)
{
    return a<b?a:b;
}

long long BreakMax(int low,int high)
{
    if (low==high)
        return num[low];
    long long left,right;
    long long max=0;
    int i;
    for (i=low;i<high;i++)
    {
        if (vis[low][i])
            left=s[low][i];
        else
        {
            left=s[low][i]=BreakMax(low,i);
            vis[low][i]=1;
        }
        if (vis[i+1][high])
            right=s[i+1][high];
        else
        {
            right=s[i+1][high]=BreakMax(i+1,high);
            vis[i+1][high]=1;
        }
        if (op[i]==0 && left+right>max)
            max=left+right;
        if (op[i]==1 && left*right>max)
            max=left*right;
    }
    return max;
}

long long BreakMin(int low,int high)
{
    if (low==high)
        return num[low];
    long long left,right;
    long long min=9223372036854775807LL;
    int i;
    for (i=low;i<high;i++)
    {
        if (vis[low][i])
            left=s[low][i];
        else
        {
            left=s[low][i]=BreakMin(low,i);
            vis[low][i]=1;
        }
        if (vis[i+1][high])
            right=s[i+1][high];
        else
        {
            right=s[i+1][high]=BreakMin(i+1,high);
            vis[i+1][high]=1;
        }
        if (op[i]==0 && left+right<min)
            min=left+right;
        if (op[i]==1 && left*right<min)
            min=left*right;
    }
    return min;
}

int main()
{
//    freopen("in.txt","r",stdin);
    int i;
    int temp;
    long long ans1,ans2;
    while (scanf("%s",str)==1)
    {
        if (!strcmp(str,"END"))
            break;
        temp=0;
        n=1;
        for (i=0;str[i]!='\0';i++)
        {
            if (str[i]>='0'&&str[i]<='9')
                temp=temp*10+str[i]-'0';
            else
            {
                num[n]=temp;
                temp=0;
                if (str[i]=='+')
                    op[n]=0;
                else op[n]=1;
                n++;
            }
        }
        num[n]=temp;
        memset(vis,0,sizeof(vis));
        ans2=BreakMax(1,n);
        memset(vis,0,sizeof(vis));
        ans1=BreakMin(1,n);
        printf("%lld %lld\n",ans1,ans2);
    }
    return 0;
}