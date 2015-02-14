#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

char mc[30][5] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
                  "....", "..", ".---", "-.-", ".-..", "--", "-.",
                  "---", ".--.", "--.-", ".-.", "...", "-", "..-",
                  "...-", ".--", "-..-", "-.--", "--..",
                  "..--", ".-.-", "---.", "----"};

int getid(char ch)
{
    if (ch >= 'A' && ch <='Z') return ch-'A';
    if (ch == '_') return 26;
    if (ch == ',') return 27;
    if (ch == '.') return 28;
    if (ch == '?') return 29;
}

char getch(int id)
{
    if (id < 26) return 'A'+id;
    if (id == 26) return '_';
    if (id == 27) return ',';
    if (id == 28) return '.';
    if (id == 29) return '?';
}

char s[1010], ss[4010], p[5];
int n, len[1010];

int main()
{
    while (scanf("%s", s) == 1)
    {
        n = strlen(s);
        ss[0] = 0;
        for (int i=0;i<n;i++)
        {
            int id = getid(s[i]);
            strcat(ss, mc[id]);
            len[i] = strlen(mc[id]);
        }
        reverse(len, len+n);
        for (int i=0,j=0;i<n;i++)
        {
            int l = len[i];
            for (int k=0;k<l;k++) p[k] = ss[j++];
            p[l] = 0;
            for (int k=0;k<30;k++)
                if (strcmp(p, mc[k]) == 0) printf("%c", getch(k));
        }
        puts("");
    }
    return 0;
}
