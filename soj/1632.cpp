#include <iostream>
#include <map>
using namespace std;

int CalInversion(char a[],int n)
{
    int s=0;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if (a[j]<a[i])
                s++;
        }
    }
    return s;
}

int main()
{
    int n,m;
    while (cin>>n>>m)
    {
        multimap<int,char*> DNA;
        multimap<int,char*>::const_iterator pos;
        char a[110][60];
        for (int t=0;t<m;t++)
        {
            cin>>a[t];
            DNA.insert(pair<int,char*>(CalInversion(a[t],n),a[t]));
        }
        for (pos=DNA.begin();pos!=DNA.end();pos++)
        {
            cout<<pos->second<<endl;
        }
        cout<<"********************"<<endl;
    }
    return 0;
}