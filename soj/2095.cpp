#include <stdio.h>
#include <set>
using namespace std;

int main()
{
    multiset<int> data;
    int t;
    char cmd[10];
    int n;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%s",cmd);
        if (cmd[0]=='a')
        {
            scanf("%d",&n);
            data.insert(n);
        }
        else if (cmd[0]=='d' && !data.empty())
        {
            data.erase(data.begin());
        }
        else if (cmd[0]=='q' && !data.empty())
        {
            printf("%d\n",*data.begin());
        }
    }
}