#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<string>
#include<set>
#include<map>
#include<list>
#include<cmath>
#include<queue>
#include<vector>
#include<algorithm>
inline int Abs(int a){return a<0?-a:a;}
inline int min(int a,int b){if (a==-1) return b;return a<b?a:b;}
inline int max(int a,int b){if (a==-1) return b;return a>b?a:b;}
inline void swap(int &a,int &b){if (a<=b) return;int t=a;a=b;b=t;}
inline double Abs(double a){return a<0?-a:a;}
inline double min(double a,double b){if (a==-1) return b;return a<b?a:b;}
inline double max(double a,double b){if (a==-1) return b;return a>b?a:b;}
inline void swap(double &a,double &b){if (a<=b) return;double t=a;a=b;b=t;}
inline long long Abs(long long a){return a<0?-a:a;}
inline long long min(long long a,long long b){if (a==-1) return b;return a<b?a:b;}
inline long long max(long long a,long long b){if (a==-1) return b;return a>b?a:b;}
inline void swap(long long &a,long long &b){if (a<=b) return;long long t=a;a=b;b=t;}
using namespace std;

const int N=110;

int f[N][N];
int n,m;

int main(){
    int cas;
    scanf("%d",&cas);
    while (cas--){
        scanf("%d%d",&n,&m);
        memset(f,-1,sizeof(f));
        for (int i=1;i<=m;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            f[a][b]=min(f[a][b],c);
        }
        for (int k=1;k<=n;k++)
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++){
                    if (f[i][k]==-1||f[k][j]==-1) continue;
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
                }
        int ans=-1;
        for (int i=1;i<=n;i++)
            if (f[i][i]!=-1)
                ans=min(ans,f[i][i]);
        printf("%d\n",ans);
    }
    return 0;
}