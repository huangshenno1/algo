#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n,x;
    while (cin>>n>>x)
    {
        set<int> b;
        bool flag=0;
        for (int i=0;i<n;i++)
        {
            int a;
            cin>>a;
            if (!flag)
            {
                if (b.count(x-a))
                {
                    flag=1;
                }
                else
                {
                    b.insert(a);
                }
            }
        }
        if (flag)
            cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}