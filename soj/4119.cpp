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

int T,a,b;
int cnt[40];
int ans;

void init()
{
    cnt[0]=0;
    for (int i=1;i<=32;i++)
        cnt[i]=(cnt[i-1]<<1)+i;
}

int f(int x)
{
    if (x<0) return 0;
    int y=1,k=0;
    while (x>=(y<<1)-1) {y<<=1; k++;}
    return cnt[k]+k+1+f(x-y);
}

int main()
{
    init();
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",f(b)-f(a-1));
    }
    return 0;
}
