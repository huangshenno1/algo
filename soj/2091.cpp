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

int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        if (n==0) puts("1");
        else printf("%d\n",n*n-n+2);
    }
    return 0;
}
