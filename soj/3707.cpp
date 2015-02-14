#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;

int T,len,x,ans;
char digit[10],tmp[10],tt;
map<string,bool> mp;
map<int,bool> mp2;

bool isprime(int x)
{
    if (x<=1) return 0;
    for (int i=2;i*i<=x;i++)
        if (x%i==0) return 0;
    return 1;
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",digit);
        len=strlen(digit);
        sort(digit,digit+len);
        ans=0;
        mp.clear();
        mp2.clear();
        for (int k=0;k<(1<<len);k++)
        {
            tt=0;
            for (int i=0;i<len;i++)
                if (k&(1<<i)) tmp[tt++]=digit[i];
            tmp[tt]=0;
            if (mp[tmp]) continue;
            do
            {
                x=0;
                for (int i=0;i<tt;i++) x=x*10+tmp[i]-'0';
                if (mp2[x]) continue;
                mp2[x]=1;
                if (isprime(x)) ans++;
            }while (next_permutation(tmp,tmp+tt));
        }
        printf("%d\n",ans);
    }
    return 0;
}
