#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    char str[5];
    while (scanf("%s", str) == 1)
    {
        n = 1;
        while (scanf("%s", str) == 1 && strcmp(str, "END") != 0) n++;
        if (n & 1) printf("B %d\n", n);
        else printf("W %d\n", n);
    }
    return 0;
}
