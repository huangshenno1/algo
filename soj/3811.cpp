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

int T;
int x,y;
int d1,d2;

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&x,&y);
        if (x>=0&&y<=0) d1=abs(x)+abs(y);
        else if (x<0&&y<0) d1=abs(x)+abs(y);
        else if (x<0&&y>=0) d1=abs(x)+abs(y)+2;
        else d1=abs(x)+abs(y)+4;
        if (x>=0&&y>=0) d2=d1;
        else if (x>=0&&y<0) d2=d1+4;
        else if (x<0&&y<0) d2=d1+4;
        else d2=d1+2;
        printf("%d %d\n",d1,d2);
    }
    return 0;
}
