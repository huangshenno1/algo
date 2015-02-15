#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100010;
const int maxnode = 100010;
const int maxr = 100010;

struct DLX
{
    int n, sz;
    int S[maxn];
    int row[maxnode], col[maxnode];
    int L[maxnode], R[maxnode], U[maxnode], D[maxnode];
    int ansd, ans[maxr];

    void init(int n)
    {
        this->n = n;
        for (int i = 0; i <= n; i++)
            {U[i] = i; D[i] = i; L[i] = i-1; R[i] = i+1;}
        R[n] = 0; L[0] = n;
        sz = n + 1;
        memset(S, 0, sizeof(S));
    }

    void addRow(int r, vector<int> columns)
    {
        int first = sz;
        for (int i = 0; i < columns.size(); i++)
        {
            int c = columns[i];
            U[sz] = U[c]; D[sz] = c; L[sz] = sz-1; R[sz] = sz+1;
            D[U[c]] = sz; U[c] = sz;
            row[sz] = r; col[sz] = c;
            S[c]++; sz++;
        }
        R[sz-1] = first; L[first] = sz - 1;
    }

    #define FOR(i,A,s) for (int i = A[s]; i != s; i = A[i])

    void remove(int c)
    {
        L[R[c]] = L[c]; R[L[c]] = R[c];
        FOR(i,D,c) FOR(j,R,i) { U[D[j]] = U[j]; D[U[j]] = D[j]; S[col[j]]--; }
    }

    void restore(int c)
    {
        FOR(i,U,c) FOR(j,L,i) { S[col[j]]++; U[D[j]] = j; D[U[j]] = j; }
        L[R[c]] = c; R[L[c]] = c;
    }

    bool dfs(int d)
    {
        if (R[0] == 0) { ansd = d; return true; }
        int c = R[0];
        FOR(i,R,0) if (S[i] < S[c]) c = i;
        remove(c);
        FOR(i,D,c)
        {
            ans[d] = row[i];
            FOR(j,R,i) remove(col[j]);
            if (dfs(d+1)) return true;
            FOR(j,L,i) restore(col[j]);
        }
        restore(c);
        return false;
    }

    bool solve(vector<int> &v)
    {
        v.clear();
        if (!dfs(0)) return false;
        for (int i = 0; i < ansd; i++) v.push_back(ans[i]);
        return true;
    }
};

DLX dlx;
const int SLOT = 0;
const int ROW = 1;
const int COL = 2;
const int SUB = 3;

int encode(int a,int b,int c)
{
    return a*81+b*9+c+1;
}

void decode(int code,int &a,int &b,int &c)
{
    code--; c=code%9; code/=9; b=code%9; code/=9; a=code;
}

char str[100];
char puzzle[10][10];

int main()
{
    while (scanf("%s",str)==1 && strcmp(str,"end")!=0)
    {
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                puzzle[i][j]=str[i*9+j];
        dlx.init(324);
        for (int r=0;r<9;r++)
            for (int c=0;c<9;c++)
                for (int v=0;v<9;v++)
                    if (puzzle[r][c]=='.'||puzzle[r][c]=='1'+v)
                    {
                        vector<int> columns;
                        columns.push_back(encode(SLOT,r,c));
                        columns.push_back(encode(ROW,r,v));
                        columns.push_back(encode(COL,c,v));
                        columns.push_back(encode(SUB,(r/3)*3+c/3,v));
                        dlx.addRow(encode(r,c,v), columns);
                    }

        vector<int> ans;
        dlx.solve(ans);

        for (int i=0;i<ans.size();i++)
        {
            int r,c,v;
            decode(ans[i],r,c,v);
            puzzle[r][c]='1'+v;
        }
        for (int i=0;i<9;i++)
            for (int j=0;j<9;j++)
                str[i*9+j]=puzzle[i][j];
        printf("%s\n",str);
    }
    return 0;
}
