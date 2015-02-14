#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <set>
using namespace std;

int main()
{
    int rose[100000];
    multiset<int> flag_rose;
    for (int i=0;i<99999;i++)
    {
        scanf("%d",&rose[i]);
    }
    srand(time(NULL));
    for (int i=0;i<10000;i++)
    {
        int r=rand()%99999;
        flag_rose.insert(rose[r]);
    }
    int max=0;
    int flag;
    int last=-1;;
    for (multiset<int>::const_iterator p=flag_rose.begin();p!=flag_rose.end();p++)
    {
        if (*p==last)
            continue;
        last=*p;
        int t=flag_rose.count(last);
        if (t>max)
        {
            max=t;
            flag=last;
        }
    }
    printf("%d\n",flag);
    return 0;
}