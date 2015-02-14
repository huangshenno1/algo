#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    double n,p;
    int k;
    while (cin>>n>>p)
    {
        k=pow(p,1/n)+0.5;
        cout<<k<<endl;
    }
    return 0;
}