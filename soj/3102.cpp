//为什么这能过= =
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N=2000001;
int s[N],n,k,i,cur;
char ch[10*N];
int f[256];

int main() {
    for(i='0';i<='9';++i) f[i]=1;
    while (scanf("%d%d",&n,&k)!=EOF) {
        getchar();
        gets(ch);
        for (i=cur=0;i<n;++i) {
            int v=0;
            for (;f[ch[cur]]==0;cur++);
            v=ch[cur]-48;
            for (;f[ch[++cur]]==1;v=(v<<3)+(v<<1)+ch[cur]-48);
            s[i]=v;
        }
        nth_element(s,s+k-1,s+n);
        printf("%d\n",s[k-1]);
    }
    return 0;
}