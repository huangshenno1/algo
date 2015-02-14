#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 1000010;
int n, d;
char plain[maxn], cipher[maxn];

int main()
{
    while (scanf("%d", &d) == 1 && d)
    {
        getchar();
        char ch = getchar();
        n = 0;
        while (ch != '\n')
        {
            if (ch >= 'A' && ch <= 'Z') plain[n++] = ch;
            if (ch >= 'a' && ch <= 'z') plain[n++] = ch - 'a' + 'A';
            ch = getchar();
        }
        plain[n] = 0;
        for (int i=0,j=0,k=0,cc=0;cc<n;)
        {
            while (k < n)
            {
                cipher[k] = plain[i++];
                k += d;
                cc++;
                if (cc == n) break;
            }
            j++; k = j;
        }
        cipher[n] = 0;
        printf("%s\n", cipher);
    }
    return 0;
}
