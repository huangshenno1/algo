#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1000010;
struct Seg
{
    unsigned int l,r;
    bool del;
    bool operator < (const Seg temp) const
    {
        return l==temp.l?r>temp.r:l<temp.l;
    }
}seg[maxn],s[maxn];
int sz=0,n=0;

unsigned int getIP(char str[])
{
    int res=0,r,i=0;
    for (r=0;str[i]!='.';i++)
        r=r*10+str[i]-48;
    res=res*256+r;
    for (i++,r=0;str[i]!='.';i++)
        r=r*10+str[i]-48;
    res=res*256+r;
    for (i++,r=0;str[i]!='.';i++)
        r=r*10+str[i]-48;
    res=res*256+r;
    for (i++,r=0;str[i]!='\0';i++)
        r=r*10+str[i]-48;
    res=res*256+r;
    return res;
}

int main()
{
    char str[20];
    while (scanf("%s",str)==1 && str[0]!='#')
    {
        seg[sz].l=getIP(str);
        scanf("%s",str);
        seg[sz].r=getIP(str);
        if (seg[sz].l>seg[sz].r) swap(seg[sz].l,seg[sz].r);
        seg[sz].del=0;
        sz++;
    }

    sort(seg,seg+sz);
    int last=0;
    unsigned int end=seg[0].r;
    for (int i=1;i<sz;i++)
    {
        if (seg[i].l<=end)
        {
            seg[i].del=1;
            seg[last].r=max(seg[last].r,seg[i].r);
        }
        else
        {
            last=i;
            end=seg[i].r;
        }
    }
    for (int i=0;i<sz;i++)
    {
        if (!seg[i].del)
            s[n++]=seg[i];
    }

    while (scanf("%s",str)==1)
    {
        unsigned int ip=getIP(str);
        int low=0,high=n-1,mid;
        while (low<=high)
        {
            mid=(low+high)>>1;
            if (s[mid].l<=ip && s[mid].r>=ip)
            {
                printf("yes\n");
                break;
            }
            if (s[mid].l>ip)
                high=mid-1;
            if (s[mid].r<ip)
                low=mid+1;
        }
        if (low>high) printf("no\n");
    }

    return 0;
}
