#include <iostream>
#include <string>
#include <cstring>
#include <map>
using namespace std;

map<string,int> mm;
int count;
map<string,int>::iterator it;

map<int,string> dd;
map<int,string>::iterator pt;

int pre[333];
int next[333];

int num(string str)
{
    it=mm.find(str);
    if (it==mm.end())
    {
        mm.insert(pair<string,int>(str,count));
        dd.insert(pair<int,string>(count,str));
        count++;
        return count-1;
    }
    return it->second;
}

int main()
{
    int t,iCase=1,n;
    int i;
    string from,to;
    int ff,tt;
    cin>>t;
    while (t--)
    {
        cout<<"Scenario #"<<iCase++<<":"<<endl;
        cin>>n;
        count=0;
        mm.clear();
        dd.clear();
        memset(pre,-1,sizeof(pre));
        memset(next,-1,sizeof(next));
        for (i=1;i<n;i++)
        {
            cin>>from>>to;
            ff=num(from);
            tt=num(to);
            pre[tt]=ff;
            next[ff]=tt;
        }
        i=0;
        while (pre[i]!=-1)
        {
            i=pre[i];
        }
        while (i!=-1)
        {
            pt=dd.find(i);
            cout<<pt->second<<endl;
            i=next[i];
        }
        cout<<endl;
    }
    return 0;
}
