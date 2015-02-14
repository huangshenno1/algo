#include <cstdio>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

const int maxn = 100010;
int n;
string name1, name2, name3;
set<string> s;
map<string, int> m;
map<string, int>::iterator it;

int main()
{
    while (scanf("%d", &n) == 1)
    {
        s.clear(); m.clear();
        for (int i=0;i<n;i++)
        {
            cin >> name1 >> name2 >> name3;
            string tmp = name1; tmp.append(" "); tmp += name2; tmp.append(" "); tmp += name3;
            if (s.find(tmp) == s.end()) s.insert(tmp);
            else continue;
            m[name3]++;
        }
        for (it=m.begin();it!=m.end();it++)
            cout << (*it).first << " " << (*it).second << endl;
    }
    return 0;
}
