#include <stdio.h>
#include <set>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    for (int iCase=0;iCase<t;iCase++)
    {
        int n;
        scanf("%d",&n);
        multiset<int> number;
        int min=1000000001,max=0;
        int temp;
        for (int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            if (temp>max)
                max=temp;
            if (temp<min)
                min=temp;
            number.insert(temp);
        }
        if (max-min<=1)
            printf("possible\n");
        else
        {
            bool flag=1;
            for (int i=min+1;i<max;i++)
            {
                if (number.count(i)<2)
                {
                    flag=0;
                    break;
                }
            }
            if (flag)
                printf("possible\n");
            else printf("impossible\n");
        }
    }
    return 0;
}