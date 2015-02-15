/*
Simplex C(n+m)(n)
maximize:
    c[1]*x[1]+c[2]*x[2]+...+c[n]*x[n]+ans
subject to
    a[1,1]*x[1]+a[1,2]*x[2]+...a[1,n]*x[n] <= rhs[1]
    a[2,1]*x[1]+a[2,2]*x[2]+...a[2,n]*x[n] <= rhs[2]
    ......
    a[m,1]*x[1]+a[m,2]*x[2]+...a[m,n]*x[n] <= rhs[m]
限制:
    传入的矩阵必须是标准形式的.
sample:
3 3
15 17 20
0 1 -1 2
3 3 5 15
3 2 1 8
out:
OPTIMAL
76.00000
x[ 1 ] = 0.333333
x[ 2 ] = 3.000000
x[ 3 ] = 1.000000
*/
//n为元素个数,m为约束个数
//max c[]*x;
//a[][]<=rhs[];
//ans即为结果,x[]为一组解

#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define eps 1e-8
#define inf 1e15
#define OPTIMAL -1 //最优解
#define UNBOUNDED -2 //无边界的
#define FEASIBLE -3 //可行的
#define INFEASIBLE -4 //无解
#define PIVOT_OK 1 //还可以松弛
#define N 45 //变量个数
#define M 45 //约束个数
int basic[N],row[M],col[N];
double c0[N];
inline double dcmp(double x) {
    if(x>eps) return 1;
    if(x<-eps) return -1;
    return 0;
}
int Pivot(int n,int m,double *c,double a[M][N],double *rhs,int &i,int &j) {
    double min=inf;
    int k=-1;
    for(j=0;j<=n;j++)
        if(!basic[j]&&dcmp(c[j])>0)
            if(k<0||dcmp(c[j]-c[k])>0) k=j;
    j=k;
    if(k<0) return OPTIMAL;
    for(k=-1,i=1;i<=m;i++) if(dcmp(a[i][j])>0)
        if(dcmp(rhs[i]/a[i][j]-min)<0) { min=rhs[i]/a[i][j]; k=i; }
    i=k;
    if(k<0) return UNBOUNDED;
    else return PIVOT_OK;
}
int PhaseII(int n,int m,double *c,double a[M][N],double *rhs,double &ans,int PivotIndex) {
    int i,j,k,l;
    double tmp;
    while(k=Pivot(n,m,c,a,rhs,i,j),k==PIVOT_OK||PivotIndex) {
        if(PivotIndex) {
            i=PivotIndex;
            j=PivotIndex=0;
        }
        basic[row[i]]=0;
        col[row[i]]=0;
        basic[j]=1;
        col[j]=i;
        row[i]=j;
        tmp=a[i][j];
        for(k=0;k<=n;k++) a[i][k]/=tmp;
        rhs[i]/=tmp;
        for(k=1;k<=m;k++)
            if(k!=i&&dcmp(a[k][j])) {
                tmp=-a[k][j];
                for(l=0;l<=n;l++)
                a[k][l]+=tmp*a[i][l];
                rhs[k]+=tmp*rhs[i];
            }
        tmp=-c[j];
        for(l=0;l<=n;l++) c[l]+=a[i][l]*tmp;
        ans-=tmp*rhs[i];
    }
    return k;
}
int PhaseI(int n,int m,double *c,double a[M][N],double *rhs,double &ans) {
    int i,j,k=-1;
    double tmp,min=0,ans0=0;
    for(i=1;i<=m;i++)
        if(dcmp(rhs[i]-min)<0) { min=rhs[i]; k=i; }
    if(k<0) return FEASIBLE;
    for(i=1;i<=m;i++) a[i][0]=-1;
    for(j=1;j<=n;j++) c0[j]=0;
    c0[0]=-1;
    PhaseII(n,m,c0,a,rhs,ans0,k);
    if(dcmp(ans0)<0) return INFEASIBLE;
    for(i=1;i<=m;i++) a[i][0]=0;
    for(j=1;j<=n;j++) if(dcmp(c[j])&&basic[j]) {
        tmp=c[j];
        ans+=rhs[col[j]]*tmp;
        for(i=0;i<=n;i++) c[i]-=tmp*a[col[j]][i];
    }
    return FEASIBLE;
}
int simplex(int n,int m,double *c,double a[M][N],double *rhs,double &ans,double *x) {
    int i,j,k;
    for(i=1;i<=m;i++) {
        for(j=n+1;j<=n+m;j++) a[i][j]=0;
        a[i][n+i]=1; a[i][0]=0;
        row[i]=n+i; col[n+i]=i;
    }
    k=PhaseI(n+m,m,c,a,rhs,ans);
    if(k==INFEASIBLE) return k; //无解
    k=PhaseII(n+m,m,c,a,rhs,ans,0);
    for(j=0;j<=n+m;j++)x[j] = 0;
    for(i=1;i<=m;i++) x[row[i]] = rhs[i];
    return k;
}
double c[M],ans,a[M][N],rhs[M],x[N];
void init(int n,int m) { //初始化
    for(int i=0;i<=n+m;i++) {
        for(int j=0;j<=n+m;j++) a[i][j]=0;
        basic[i]=0; row[i]=0; col[i]=0;
        c[i]=0; rhs[i]=0;
    }
    ans=0;
}
void solve(int n,int m) {
    switch(simplex(n,m,c,a,rhs,ans,x)) {
        case OPTIMAL:
            printf("Nasa can spend %.0f taka.\n",ceil(m*ans));
            //for(j=1;j<=n;j++)
            //    printf("x[ %2d ] = %10lf\n",j,x[j]);
            break;
        case UNBOUNDED:
            printf("UNBOUNDED\n");break;
        case INFEASIBLE:
            printf("INFEASIBLE\n");break;
    }
}
int main() {
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF) {
        init(n,m);
        for(j=1;j<=n;j++) scanf("%lf",&c[j]);
        for(i=1;i<=m;i++) { //m个约束
            for(j=1;j<=n;j++) scanf("%lf",&a[i][j]);
            scanf("%lf",&rhs[i]); //<=rhs[i]
        }
        solve(n,m);
    }
}
