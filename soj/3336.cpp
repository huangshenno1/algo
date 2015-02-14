#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <map>
using namespace std;

const int maxnode = 500010;
const int sigma_size = 26;
int ch[maxnode][sigma_size];
int val[maxnode];
int sz;
int fail[maxnode];

int T,m;
string name;
char word[15];
map<int,string> dic;
char str[1000010];
int cnt[100010];
int ans,maxc;

void init()
{
    sz = 1;
    memset(ch[0], 0, sizeof(ch[0]));
    memset(val, 0, sizeof(val));
    memset(cnt, 0, sizeof(cnt));
    dic.clear();
    ans = 0;
}
int idx(char c) {return c - 'a';}

void insert(char *s, int v)
{
    int u = 0, n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        int c = idx(s[i]);
        if (!ch[u][c])
        {
            memset(ch[sz], 0, sizeof(ch[sz]));
            val[sz] = 0;
            ch[u][c] = sz++;
        }
        u = ch[u][c];
    }
    val[u] = v;
}

void mark(int j)
{
    if (j)
    {
        cnt[val[j]]++;
        mark(fail[j]);
    }
}

void find(char *T)
{
    int n = strlen(T);
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        int c = idx(T[i]);
        j = ch[j][c];
        if (val[j]) mark(j);
        else if (fail[j]) mark(fail[j]);
    }
}

void getFail()
{
    queue<int> q;
    fail[0] = 0;
    for (int c = 0; c < sigma_size; c++)
    {
        int u = ch[0][c];
        if (u) {fail[u] = 0; q.push(u);}
    }
    while (!q.empty())
    {
        int r = q.front(); q.pop();
        for (int c = 0; c < sigma_size; c++)
        {
            int u = ch[r][c];
            if (!u) {ch[r][c] = ch[fail[r]][c];    continue;}
            q.push(u);
            int v = fail[r];
            while (v && !ch[v][c]) v = fail[v];
            fail[u] = ch[v][c];
        }
    }
}

int main()
{
    scanf("%d",&T);
    while (T--)
    {
        scanf("%s",str);
        scanf("%d",&m);
        init();
        for (int i=1;i<=m;i++)
        {
            cin>>name;
            dic[i]=name;
            scanf("%s",word);
            insert(word,i);
        }
        getFail();
        find(str);
        maxc=0; ans=0;
        for (int i=1;i<=m;i++)
        {
            if (cnt[i]==maxc) ans=0;
            if (cnt[i]>maxc)
            {
                maxc=cnt[i];
                ans=i;
            }
        }
        if (ans) cout<<dic[ans]<<endl;
        else puts("No-solution!");
    }
    return 0;
}