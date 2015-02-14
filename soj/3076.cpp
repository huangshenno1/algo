#include <stdio.h>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string,int> m;
    map<string,int>::iterator it;
    int n;
    int i,j;
    char temp[310];
    string str;
    while (scanf("%d",&n)==1)
    {
        m.clear();
        while (n--)
        {
            scanf("%s",temp);
            str=(string)temp;
            it=m.find(str);
            if (it!=m.end())
            {
                printf("%d\n",it->second);
                it->second++;
            }
            else
            {
                printf("0\n");
                m.insert(pair<string,int>(str,1));
            }
        }
    }
    return 0;
}