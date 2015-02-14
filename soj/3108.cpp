#include <cstdio>
#include <cstring>

const int maxn = 2005;
char str1[maxn],str2[maxn];
int len1,len2;
int dp[2][maxn];

int main()
{
    while (scanf("%s",str1+1)==1)
    {
        scanf("%s",str2+1);
        len1=strlen(str1+1);
        len2=strlen(str2+1);
        for (int j=0;j<=len2;j++)
            dp[0][j]=j;
        bool flag=0;
        for (int i=1;i<=len1;i++)
        {
            flag^=1;
            dp[flag][0]=i;
            for (int j=1;j<=len2;j++)
            {
                dp[flag][j] = dp[flag^1][j-1] + (str1[i]!=str2[j]);
                if (dp[flag^1][j]+1 < dp[flag][j]) dp[flag][j] = dp[flag^1][j]+1;
                if (dp[flag][j-1]+1 < dp[flag][j]) dp[flag][j] = dp[flag][j-1]+1;
            }
        }
        printf("%d\n",dp[flag][len2]);
    }
    return 0;
}