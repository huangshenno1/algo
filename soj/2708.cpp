#include <cstdio>

const int LEN = 20;

int key[8][4]={
    0,1,2,-1,
    3,4,5,-1,
    6,7,8,-1,
    9,10,11,-1,
    12,13,14,-1,
    15,16,17,18,
    19,20,21,-1,
    22,23,24,25};
double st[26], p[26][26];
double dp[LEN][4];
int pre[LEN][4];
char ans[LEN];

int main()
{
    for (int i=0;i<26;i++)
        scanf("%lf",&st[i]);
    for (int i=0;i<26;i++)
        for (int j=0;j<26;j++)
            scanf("%lf",&p[i][j]);

    int m;
    scanf("%d",&m);
    while (m--)
    {
        char s[LEN];
        scanf("%s",s);
        for (int j=0;j<4;j++)
            dp[0][j] = key[s[0]-'2'][j]>=0 ? st[key[s[0]-'2'][j]] : 0;

        int len=1;
        for (int i=1;s[i]!='\0';i++,len++)
        {
            for (int j=0;j<4;j++)
            {
                dp[i][j]=0;
                if (key[s[i]-'2'][j]<0) continue;
                for (int k=0;k<4;k++)
                {
                    if (key[s[i-1]-'2'][k]<0) continue;
                    if (dp[i-1][k]*p[key[s[i-1]-'2'][k]][key[s[i]-'2'][j]] > dp[i][j])
                    {
                        dp[i][j] = dp[i-1][k]*p[key[s[i-1]-'2'][k]][key[s[i]-'2'][j]];
                        pre[i][j] = k;
                    }
                }
            }
        }

        int a;
        double b=0;
        for (int j=0;j<4;j++)
        {
            if (dp[len-1][j]>b)
            {
                b=dp[len-1][j];
                a=j;
            }
        }
        ans[len-1]=key[s[len-1]-'2'][a]+'a';
        for (int k=len-1;k>0;k--)
        {
            a=pre[k][a];
            ans[k-1]=key[s[k-1]-'2'][a]+'a';
        }
        ans[len]='\0';

        printf("%s\n",ans);
    }

    return 0;
}