#include <cstdio>
#include <set>
#include <string>
using namespace std;

set<string> song;
set<string>::iterator it;

int main()
{
    int t,n,m;
    char name[510];
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        getchar();
        while (n--)
        {
            gets(name);
            string temp(name);
            song.insert(temp);
        }
        while (m--)
        {
            gets(name);
            string temp(name);
            it=song.find(temp);
            if (it==song.end())
                puts(name);
        }
    }
    return 0;
}