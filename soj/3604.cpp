#include <cstdio>
#include <map>
using namespace std;

const int maxn = 60;

int t,n;
struct Node
{
    char value;
    int parent;
    int lchild, rchild;
}node[maxn];
map<char, int> dic;
int cnt;

void output(int i, int depth)
{
    if (node[i].lchild!=-1 && node[i].rchild!=-1)
    {
        if (node[node[i].lchild].value > node[node[i].rchild].value)
        {
            int t=node[i].lchild;
            node[i].lchild=node[i].rchild;
            node[i].rchild=t;
        }
    }
    if (node[i].lchild!=-1) output(node[i].lchild, depth+1);
    for (int j=0;j<depth;j++) printf(" ");
    printf("%c\n",node[i].value);
    if (node[i].rchild!=-1) output(node[i].rchild, depth+1);
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        dic.clear();
        cnt=0;
        for (int i=0;i<n;i++)
            node[i].parent=node[i].lchild=node[i].rchild=-1;
        for (int i=1;i<n;i++)
        {
            char a,b;
            scanf("\n%c %c",&a,&b);
            if (dic.find(a)==dic.end())
            {
                dic[a]=cnt;
                node[cnt++].value=a;
            }
            if (dic.find(b)==dic.end())
            {
                dic[b]=cnt;
                node[cnt++].value=b;
            }
            if (node[dic[a]].lchild==-1) node[dic[a]].lchild=dic[b];
            else node[dic[a]].rchild=dic[b];
            node[dic[b]].parent=dic[a];
        }
        int rt;
        for (int i=0;i<n;i++)
            if (node[i].parent==-1) {rt=i; break;}
        output(rt, 0);
    }
    return 0;
}