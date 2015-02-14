#include <stdio.h>
#include <map>
using namespace std;
#define N 1000000000

int f[1428]={1,1,2,1};

map<int,long long> tree[1428];
map<int,long long>::iterator it;
map<int,long long>::iterator it1;
map<int,long long>::iterator it2;

int Abs(int a)
{
    return a>0?a:-a;
}

int Max(int a,int b)
{
    return a>b?a:b;
}

int main()
{
    long long i,j,k,t;
    tree[1].insert(pair<int,long long>(1,1));
    tree[2].insert(pair<int,long long>(2,2));
    tree[3].insert(pair<int,long long>(2,1));
    for (i=4;i<=1427;i++)
    {
        for (j=1;j<i-1;j++)
        {
            k=i-1-j;
            for (it1=tree[j].begin();it1!=tree[j].end();it1++)
            {
                for (it2=tree[k].begin();it2!=tree[k].end();it2++)
                {
                    if (Abs(it1->first-it2->first)<=1)
                    {
                        t=Max(it1->first+1,it2->first+1);
                        it=tree[i].find(t);
                        if (it==tree[i].end())
                            tree[i].insert(pair<int,long long>(t,(it1->second*it2->second)%N));
                        else it->second=(it->second+(it1->second*it2->second)%N)%N;
                    }
                }
            }
        }
        f[i]=0;
        for (it=tree[i].begin();it!=tree[i].end();it++)
            f[i]=(f[i]+it->second)%N;
    }
    
    int n;
    while (scanf("%d",&n)==1)
    {
        printf("%09d\n",f[n]);
    }
    return 0;
}