#include <cstdio>
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string,int> dic;
int p[300],l[300],n=0;

int father(int x)
{
    if (p[x]==x) return x;
    int y=father(p[x]);
    l[x]=l[p[x]]+1;
    return y;
}

int main()
{
    string str1,str2;
    int x,y;
    for (int i=0;i<300;i++)
    {
        p[i]=i;
        l[i]=0;
    }
    while (cin>>str1>>str2)
    {
        if (str1.compare("no.child")==0 && str2.compare("no.parent")==0) break;
        if (dic.find(str1)==dic.end())
        {
            x=n;
            dic[str1]=n++;
        }
        else x=dic[str1];
        if (dic.find(str2)==dic.end())
        {
            y=n;
            dic[str2]=n++;
        }
        else y=dic[str2];
        p[x]=y;
    }
    while (cin>>str1>>str2)
    {
        if (dic.find(str1)==dic.end() || dic.find(str2)==dic.end())
        {
            puts("no relation");
            continue;
        }
        x=dic[str1]; y=dic[str2];
        if (father(x)!=father(y))
        {
            puts("no relation");
            continue;
        }
        if (p[x]==p[y])
        {
            puts("sibling");
            continue;
        }
        if (l[x]>l[y])
        {
            bool f=0;
            int a=x;
            for (int i=l[x]-l[y];i>0;i--)
            {
                a=p[a];
                if (a==y)
                {
                    f=1;
                    break;
                }
            }
            if (f)
            {
                if (l[x]-l[y]==1) puts("child");
                else
                {
                    for (int i=l[x]-l[y]-2;i>0;i--) printf("great ");
                    puts("grand child");
                }
                continue;
            }
            int b=y;
            int k=0;
            while (a!=b)
            {
                a=p[a];
                b=p[b];
                k++;
            }
            printf("%d cousin removed %d\n",k-1,l[x]-l[y]);
            continue;
        }
        else if (l[x]<l[y])
        {
            bool f=0;
            int b=y;
            for (int i=l[y]-l[x];i>0;i--)
            {
                b=p[b];
                if (b==x)
                {
                    f=1;
                    break;
                }
            }
            if (f)
            {
                if (l[y]-l[x]==1) puts("parent");
                else
                {
                    for (int i=l[y]-l[x]-2;i>0;i--) printf("great ");
                    puts("grand parent");
                }
                continue;
            }
            int a=x;
            int k=0;
            while (a!=b)
            {
                a=p[a];
                b=p[b];
                k++;
            }
            printf("%d cousin removed %d\n",k-1,l[y]-l[x]);
            continue;
        }
        else
        {
            int a=x, b=y;
            int k=0;
            while (a!=b)
            {
                a=p[a];
                b=p[b];
                k++;
            }
            printf("%d cousin\n",k-1);
            continue;
        }
    }
    return 0;
}