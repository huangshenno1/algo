#include <cstdio>
#include <cstring>
#include <cstdlib>
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

const double PI = acos(-1.0);
int T,m,n;
double t,c,r;
double s1,s2,s3,s4;
double ans1,ans2,ans3,ans4;

int main()
{
    scanf("%d",&T);
    for (int cas=1;cas<=T;cas++)
    {
        scanf("%d%d%lf%lf",&m,&n,&t,&c);
        r=c/2;
        s1=(t-c)*(t-c);
        s2=(t-c)*r;
        s4=r*r*PI/4;
        s3=(t*t-s1-s2*4-s4*4)/4;
        ans1=s1*m*n+s2*(m+n)*2+s3*4+s4*4;
        ans2=s2*(m*n*4-m*2-n*2)+s3*(m*4+n*4-8)+s4*(m*4+n*4-8);
        ans3=s3*(m*n*4-m*4-n*4+4);
        ans4=s4*(m*n*4-m*4-n*4+4);
        printf("Case %d:\n",cas);
        printf("Probability of covering 1 tile  = %.4lf%%\n",ans1*100/t/t/m/n);
        printf("Probability of covering 2 tiles = %.4lf%%\n",ans2*100/t/t/m/n);
        printf("Probability of covering 3 tiles = %.4lf%%\n",ans3*100/t/t/m/n);
        printf("Probability of covering 4 tiles = %.4lf%%\n",ans4*100/t/t/m/n);
        printf("\n");
    }
    return 0;
}