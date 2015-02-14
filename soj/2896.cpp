#include <cstdio>
#include <cstring>
using namespace std;

char num[5100];
int n;
long long dp[5100];

long long f(int i)
{
    if (dp[i]) return dp[i];
    if (i<=1) return dp[i]=1;
    if (num[i-1]=='0') return dp[i]=f(i-2);
    if (num[i-2]=='1'||num[i-2]=='2') return dp[i]=f(i-2)+f(i-1);
    return dp[i]=f(i-1);
}

int main()
{
    while (scanf("%s",num)==1 && num[0]!='0')
    {
        n=strlen(num);
        memset(dp,0,sizeof(dp));
        printf("%lld\n",f(n));
    }
    return 0;
}
