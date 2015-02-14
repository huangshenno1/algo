#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    for (int iCase=0;iCase<n;iCase++)
    {
        int x,y;
        int number;
        cin>>x>>y;
        if (x==y)
        {
            if (x%2)
            {
                number=2*x-1;
            }
            else
            {
                number=2*x;
            }
            cout<<number<<endl;
        }
        else if (x-y==2)
        {
            if (x%2)
            {
                number=2*x-3;
            }
            else
            {
                number=2*x-2;
            }
            cout<<number<<endl;
        }
        else
        {
            cout<<"No Number"<<endl;
        }
    }
    return 0;
}