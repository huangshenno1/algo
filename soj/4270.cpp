//test

#include <math.h>
#include <cstdio>
#include<algorithm>
using namespace std;
const  int maxn = 100010;
const double eps = 1e-8;
inline int max(int x,int y){return x>y?x:y;}
inline double  max(double x,double y) {return x>y?x:y;}
inline double min(double a,double b){    return a<b?a:b;}
inline double sgn(double x) {return fabs(x)<eps?0:(x>0?1:-1);}
struct point{
    double x,y;
    point operator + (const point& t) const {
        point tmp;
        tmp.x = x + t.x;
        tmp.y = y + t.y;
        return tmp;
    }
    bool operator == (const point& t) const {
        return sgn(x-t.x)==0 && sgn(y-t.y)==0;
    }
}p[maxn],set[maxn];
struct Seg{point s,e;};
struct Line {  double a, b, c;};
inline double dist(point a,point b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
bool cmp(point a,point b) {return (a.x<b.x || fabs(a.x-b.x)<eps && a.y<b.y);}
inline double cross(point a,point b,point c){return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);}
//判断线段共线
bool chonghe(point a,point b,point c,point d){return !sgn(cross(a,b,c)) && !sgn(cross(a,b,d));}
//判断a,b直线是否与c,d线段相交
bool Inter(point a,point b,point c,point d){return sgn(cross(a,b,c))*sgn(cross(a,b,d))<=0;}
bool dotOnSeg(point p, point s, point e) {                
    if ( p == s || p == e )     return true;
    return sgn(cross(s,e,p))==0 && sgn((p.x-s.x)*(p.x-e.x))<=0 && sgn((p.y-s.y)*(p.y-e.y))<=0;
} 
Line Turn(point s, point e) {                                    
    Line ln;
    ln.a =s.y - e.y ;
    ln.b =e.x - s.x;
    ln.c =s.x*e.y - e.x*s.y;
    return ln;
}
bool Intersect(point p1, point p2, point p3, point p4, point& p) {
    double a1, b1, c1, a2, b2, c2, d;
    a1 = p1.y - p2.y; b1 = p2.x - p1.x; c1 = p1.x*p2.y - p2.x*p1.y;
    a2 = p3.y - p4.y; b2 = p4.x - p3.x; c2 = p3.x*p4.y - p4.x*p3.y;
    d = a1*b2 - a2*b1;
    if ( fabs(d) < eps )    return false;
    p.x = (-c1*b2 + c2*b1) / d;
    p.y = (-a1*c2 + a2*c1) / d;
    return true;
}
bool point_in_polygon(point o, point* p, int n) {
    int i, t;
    point a, b;
    p[n] = p[0];    t = 0;
    for (i=0; i < n; i++) {
        if ( dotOnSeg(o, p[i], p[i+1]) )        return true;
        a = p[i]; b = p[i+1];
        if ( a.y > b.y ) {
            point tmp = a; a = b; b = tmp;
        }
        if ( cross(o, a, b) < -eps && a.y < o.y-eps && o.y < b.y+eps )
            t++;
    }
    return t&1;
}
int tot,n,m;
double solve(){
     double ans=0;
     sort(set+1,set+tot+1,cmp);
     tot=unique(set+1,set+1+tot)-set-1;
     for(int i=1;i<tot;i++){
          point tmp;
          tmp.x=(set[i]+set[i+1]).x/2;tmp.y=(set[i]+set[i+1]).y/2;
          bool yes=point_in_polygon(tmp,p,n);
          if(yes)  ans+=dist(set[i],set[i+1]);
     }
     return ans;
}
int main(){
    int i,j;
    while(scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;
        for(i=0;i<n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);p[n]=p[0];
        while(m--){
            Seg seg;tot=0;
            scanf("%lf%lf%lf%lf",&seg.s.x,&seg.s.y,&seg.e.x,&seg.e.y);
            for(j=0;j<n;j++){
                point pp;
                if(chonghe(seg.s,seg.e,p[j],p[j+1]))  set[++tot]=p[j],set[++tot]=p[j+1];
                if(Inter(seg.s,seg.e,p[j],p[j+1]))
                if(Intersect(seg.s,seg.e,p[j],p[j+1],pp)) set[++tot]=pp; 
            }
            if(tot==0)
            {
                printf("0.000\n");
                continue;
            }
            set[++tot]=seg.s;set[++tot]=seg.e;
            printf("%.3lf\n",solve());
        }
    }
   return 0;
}