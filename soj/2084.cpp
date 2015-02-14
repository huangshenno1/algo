#include <iostream>
#include <ctype.h>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string,int> word;
    map<string,int>::iterator it;
    string str;
    cin>>str;
    while (str[0]!='#')
    {
        for (int i=0;i<str.length();i++)
            str[i]=tolower(str[i]);
        it=word.find(str);
        if (it==word.end())
            word.insert(pair<string,int>(str,1));
        else it->second++;
        cin>>str;
    }
    int max=0;
    string ans;
    for (it=word.begin();it!=word.end();it++)
    {
        if (it->second>max)
        {
            max=it->second;
            ans=it->first;
        }
    }
    cout<<ans<<endl;
    return 0;
}