#include <cstdio>

int T, cas = 1;
int h, m, s;
char hh[10], mm[10], ss[10];
char ans1[20], ans2[20];

void pre(int x, char *a)
{
    for (int i=5;i>=0;i--,x>>=1)
        a[i] = '0' + (x & 1);
}

void go()
{
    int j = 0;
    for (int i=0;i<6;i++)
        ans1[j++] = hh[i], ans1[j++] = mm[i], ans1[j++] = ss[i];
    ans1[j] = 0;

    j = 0;
    for (int i=0;i<6;i++) ans2[j++] = hh[i];
    for (int i=0;i<6;i++) ans2[j++] = mm[i];
    for (int i=0;i<6;i++) ans2[j++] = ss[i];
    ans2[j] = 0;
}

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d:%d:%d", &h ,&m, &s);
        pre(h, hh); pre(m, mm); pre(s, ss);
        go();
        printf("%d %s %s\n", cas++, ans1, ans2);
    }
    return 0;
}
