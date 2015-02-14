#include <iostream>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

const int maxn = 210;
int m,n;
map<int,string> dic;
int c[maxn],next[maxn];
bool g[maxn][maxn],vis[maxn];
queue<int> Q;
bool flag;

void init()
{
    int i,j,temp,count;
    string s;
    for (i=0;i<n;i++)
    {
        cin>>s;
        dic[i]=s;
        c[i]=s[0]*1000000+s[1]*10000+s[2]*100+s[3];
    }
    for (i=0;i<n;i++)
    {
        for (j=0;j<=i;j++)
        {
            temp=abs(c[i]-c[j]);
            count=0;
            if (temp%100) count++; temp/=100;
            if (temp%100) count++; temp/=100;
            if (temp%100) count++; temp/=100;
            if (temp) count++;

            if (count==1) g[i][j]=g[j][i]=1;
            else g[i][j]=g[j][i]=0;
        }
    }
}

int main()
{
    string sfrom,sto;
    int from,to;
    int i,j;
    while (cin>>n>>m)
    {
        init();
        while (m--)
        {
            cin>>sfrom>>sto;
            for (i=0;i<n;i++)
            {
                if (dic[i]==sfrom) from=i;
                if (dic[i]==sto) to=i;
            }
            while (!Q.empty()) Q.pop();
            memset(vis,0,sizeof(vis));
            vis[to]=1; next[to]=-1;
            Q.push(to);
            flag=0;
            while (!Q.empty())
            {
                j=Q.front(); Q.pop();
                for (i=0;i<n;i++)
                {
                    if (!vis[i] && g[i][j])
                    {
                        next[i]=j;
                        if (i==from)
                        {
                            flag=1;
                            break;
                        }
                        vis[i]=1;
                        Q.push(i);
                    }
                }
                if (flag)
                break;
            }
            i=from;
            while (next[i]!=-1)
            {
                cout<<dic[i]<<' ';
                i=next[i];
            }
            cout<<dic[i]<<endl;
        }
    }
    return 0;
}
