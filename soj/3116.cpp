#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    while (cin>>n)
    {
        multiset<int> proposition;
        multiset<int>::reverse_iterator p;
        for (int temp,i=0;i<n;i++)
        {
            cin>>temp;
            if (temp<=n)
            {
                proposition.insert(temp);
            }
        }
        int last=0;
        bool flag=0;
        for (p=proposition.rbegin();p!=proposition.rend();p++)
        {
            if (last==*p)
                continue;
            last=*p;
            if (proposition.count(last)==last)
            {
                cout<<last<<endl;
                flag=1;
                break;
            }
        }
        if (!flag)
        {
            cout<<"-1"<<endl;
        }
    }
    return 0;
}