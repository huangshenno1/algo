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

int T,n,m,w;
set<int> s;
set<int>:: iterator it1,it2;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        s.clear();
        while (n--)
        {
            scanf("%d",&m);
            while (m--)
            {
                scanf("%d",&w);
                s.insert(w);
            }
            if (s.size()<2) {puts("-1 -1"); continue;}
            it1=s.begin(); it2=s.end();
            it1++; it2--; it2--;
            printf("%d %d\n",*it1,*it2);
            s.erase(it1); s.erase(it2);
        }
    }
    return 0;
}
