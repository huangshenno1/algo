#include <iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for (int iCase=0;iCase<t;iCase++)
    {
        int a[110][110],b[110][110];
        int m,n,p;
        int i,k,j;
        cin>>m>>n>>p;
        for (i=0;i<m;i++)
            for (k=0;k<n;k++)
                cin>>a[i][k];
        for (k=0;k<n;k++)
            for (j=0;j<p;j++)
                cin>>b[k][j];
        for (i=0;i<m;i++)
        {
            for (j=0;j<p;j++)
            {
                int s=0;
                for (k=0;k<n;k++)
                    s+=a[i][k]*b[k][j];
                cout<<s;
                if (j<p-1)
                    cout<<' ';
                else cout<<endl;
            }
        }
    }
    return 0;
}