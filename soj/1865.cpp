#include <iostream>
using namespace std;

long long sum[510][510];
bool flag[510][510]={0};

long long Q(int a,int b)
{
    if (a<b)
        return Q(a,a);
    else if (a==1||b==1)
    {
        flag[a][b]=1;
        sum[a][b]=1;
        return 1;
    }
    else if (flag[a][b])
        return sum[a][b];
    else if (a==b)
    {
        flag[a][b]=1;
        sum[a][b]=1+Q(a,a-1);
        return sum[a][b];
    }
    else
    {
        flag[a][b]=1;
        sum[a][b]=Q(a,b-1)+Q(a-b,b);
        return sum[a][b];
    }
}

int main()
{
    int n;
    cin>>n;
    while (n)
    {
        cout<<Q(n,n)<<endl;
        cin>>n;
    }
    return 0;
}