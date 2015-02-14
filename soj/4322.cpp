#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int MAXN = 209;
char s[MAXN];
int w[MAXN];

void solve(){
    int cnt = 0, len = strlen(s), sum = 0;
    for(int i = 1; i < len; ++i){
        if(s[i] == '/'){
            if(sum == 64)    ++cnt;
            sum = 0;
        }else{
            sum += w[s[i]-'A'];
        }
    }
    printf("%d\n", cnt);
}

int main(){
    w['W'-'A']=64, w['H'-'A']=32, w['Q'-'A']=16, w['E'-'A']=8, w['S'-'A']=4, 
    w['T'-'A']=2, w['X'-'A']=1;
    while(scanf("%s", s) && s[0] != '*')
        solve();
    return 0;
}