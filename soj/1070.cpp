#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int T=1,n,m;
map<int,string> dic;
map<string,int> rdic;
double g[30][30];
bool flag;

int main()
{
    int i,j,k;
    string name,name2;
    double r;
    while (cin>>n && n)
    {
        for (i=0;i<n;i++)
            for (j=0;j<n;j++)
                g[i][j]=-1;
        for (i=0;i<n;i++)
        {
            cin>>name;
            dic[i]=name;
            rdic[name]=i;
        }
        cin>>m;
        for (i=0;i<m;i++)
        {
            cin>>name>>r>>name2;
            j=rdic[name]; k=rdic[name2];
            g[j][k]=r;
        }
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                for (k=0;k<n;k++)
                {
                    if (g[i][k]>=0 && g[k][j]>=0)
                        g[i][j]=max(g[i][j],g[i][k]*g[k][j]);
                }
            }
        }
        cout<<"Case "<<T++<<": ";
        flag=0;
        for (i=0;i<n;i++)
            if (g[i][i]>1)
            {
                cout<<"Yes"<<endl;
                flag=1;
                break;
            }
        if (!flag) cout<<"No"<<endl;
    }
    return 0;
}
