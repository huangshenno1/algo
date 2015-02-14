#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
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

int n;
char str[200010],tmp[100010];
int mx,id;
int p[200010],ans;

int main()
{
    while (scanf("%s",tmp+1)==1)
    {
        n=strlen(tmp+1);
        str[0]='$';
        for (int i=1;i<=n;i++) str[i<<1]=tmp[i];
        n=n*2+1;
        for (int i=1;i<=n;i+=2) str[i]='#';
        str[n+1]='%';

        ans=mx=0;
        for (int i=1;i<n;i++)
        {
            if (mx>i) p[i]=min(p[2*id-i],mx-i);
            else p[i]=1;
            for (;str[i-p[i]]==str[i+p[i]];p[i]++);
            if (i+p[i]>mx) {mx=i+p[i]; id=i;}
            if (p[i]>ans) ans=p[i];
        }

        printf("%d\n",ans-1);
    }
    return 0;
}
