#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <cmath>
#include <iostream>
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
const int maxn1 = 1010;
const int maxn2 = 100010;

char str1[maxn1],str2[maxn2],ans[maxn2];
int len1,len2;

int main()
{
    while(scanf("%s",str1)==1 && str1[0]!='0')
    {
        scanf("%s",str2);
        len1=strlen(str1);
        len2=strlen(str2);
        int i=0,j=0;
        while(j<len2)
        {
            ans[j]=(str2[j]-'A'+str1[i]-'A'+1)%26+'A';
            i++;
            i%=len1;
            j++;
        }
        ans[len2]=0;
        printf("%s\n",ans);
    }
    return 0;
}
