#include <stdio.h>
#include <stdlib.h>

int n,i;
struct GOOD
{
int j,p;
double hfm;
int no;
}good[25010];

int cmp(const void *a,const void *b)
{
struct GOOD *temp1=(struct GOOD *)a;
struct GOOD *temp2=(struct GOOD *)b;
return (int)(1000*(temp2->hfm-temp1->hfm));
}

int main()
{
while (scanf("%d",&n)==1)
{
for (i=0;i<n;i++)
{
scanf("%d%d",&good[i].j,&good[i].p);
good[i].hfm=(double)good[i].j/good[i].p;
good[i].no=i+1;
}
qsort(good,n,sizeof(struct GOOD),cmp);
printf("%d\n%d\n%d\n%d\n",good[0].p+good[1].p+good[2].p,good[0].no,good[1].no,good[2].no);
}
return 0;
}