#include <stdio.h>
#include <map>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        map<int,int> building;
        map<int,int>::iterator p;
        int n,d,min=1;
        scanf("%d",&n);
        if (n==0)
            min=0;
        while (n--)
        {
            scanf("%d",&d);
            p=building.find(d);
            if (p==building.end())
            {
                building.insert(pair<int,int>(d,1));
            }
            else
            {
                p->second++;
                if (p->second>min)
                    min=p->second;
            }
        }
        printf("%d\n",min);
    }
    return 0;
}