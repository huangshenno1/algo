#include <iostream>
using namespace std;

int main()
{
    int method[6][32];
    method[2][1]=2;
    method[3][1]=2;
    method[4][1]=2;
    method[5][1]=2;
    for (int i=2;i<32;i++)
    {
        for (int j=2;j<=5;j++)
        {
            if (i>j+1)
                method[j][i]=method[j][i-1]*2-method[j][i-j-1];
            else if (i==j+1||i==j)
                method[j][i]=method[j][i-1]*2-1;
            else method[j][i]=method[j][i-1]*2;
        }
    }

    int l;
    cin>>l;
    for (int iCase=0;iCase<l;iCase++)
    {
        int n,m;
        cin>>n>>m;
        cout<<method[m][n]<<endl;
    }
    return 0;
}