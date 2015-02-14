#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

void NewSearch(int k);
void Search(int s,int k);

int t;
int n,i,a[21],c;
bool b[21];
int sum,avg;
bool flag;

bool Greater(const int &a1,const int &a2)
{
    return a1>a2;
}

void NewSearch(int k)
{
    if (k==3)
    {
        flag=1;
        return;
    }
    Search(0,0);
}

void Search(int s,int k)
{
    if (flag)
        return;
    if (s>avg)
        return;
    if (s==avg)
    {
        c++;
        NewSearch(c);
        c--;
        return;
    }
    if (k==n)
        return;
    if (b[k]==0)
    {
        b[k]=1;
        Search(s+a[k],k+1);
        b[k]=0;
    }
    Search(s,k+1);
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        sum=0;
        flag=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if (sum%4)
        {
            printf("no\n");
            continue;
        }
        avg=sum/4;
        sort(a,a+n,Greater);
        memset(b,0,sizeof(b));
        c=0;

        NewSearch(c);

        if (flag)
            printf("yes\n");
        else printf("no\n");
    }
    return 0;
}