#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define eps 1e-6
int a[7];
double c[7],matrix[6][6],b[7];
double min(double x1,double x2,double x3,double x4){
    return min(min(x1,x2),min(x3,x4));
}
double sq(double x){
    return x*x;
}
bool judge(double x1,double x2,double x3){
    if(x1+x2>x3 && x1+x3>x2 && x2+x3>x1) return true;
    return false;
}
bool solve(){
    if(min(c[1]+c[2]+c[3],c[1]+c[5]+c[6],c[4]+c[2]+c[6],c[4]+c[5]+c[3])+eps<=max(c[1]+c[4],max(c[2]+c[5],c[3]+c[6])))
        return false;
    if(judge(c[1],c[2],c[6]) && judge(c[2],c[3],c[4]) && judge(c[1],c[3],c[5])
       && judge(c[4],c[5],c[6]))  ;
        else return false;
    for(int i=1;i<=5;i++)
        for(int j=1;j<=5;j++){
            if(i==j) matrix[i][j]=0;
            else if(i==1 || j==1) matrix[i][j]=1;
        }
    matrix[2][3]=matrix[3][2]=sq(c[1]);
    matrix[2][4]=matrix[4][2]=sq(c[2]);
    matrix[2][5]=matrix[5][2]=sq(c[3]);
    matrix[4][5]=matrix[5][4]=sq(c[4]);
    matrix[3][5]=matrix[5][3]=sq(c[5]);
    matrix[3][4]=matrix[4][3]=sq(c[6]);
    double p,q;
    int ans=1;
    for(int i=1;i<5;i++){
        if(fabs(matrix[i][i])<eps){
            ans*=-1;
            bool ok=false;
            for(int j=i+1;j<=5;j++){
                if(fabs(matrix[j][i])>eps){
                    ok=true;
                    for(int k=1;k<=5;k++){
                        swap(matrix[i][k],matrix[j][k]);
                    }
                }
                if(ok) break;
            }
            if(!ok) ans=0;
        }
        if(matrix[i][i]<0) ans*=-1;
        for(int j=i+1;j<=5;j++){
            if(fabs(matrix[j][i])<eps) continue;
            double tmp=matrix[j][i]*matrix[i][i];
            p=tmp/matrix[j][i],q=tmp/matrix[i][i];
            for(int k=i;k<=5;k++){
                matrix[j][k]=matrix[j][k]-matrix[i][k]*q/p;
            }
        }
    }
    if(matrix[5][5]<0) ans*=-1;
    if(ans>0) return true;
    return false;
}
int main(){
    int T;
    while (scanf("%d",&T) == 1){
    while(T--){
        bool ok=false;
        for(int i=0;i<6;i++) a[i]=i,scanf("%lf",&b[i]);
        while(next_permutation(a,a+6)){
            for(int i=0;i<6;i++) c[i+1]=b[a[i]];
            if(solve()){
                ok=true;
                break;
            }
        }
        if(ok) printf("YES\n");
        else printf("NO\n");
    }}
    return 0;
}