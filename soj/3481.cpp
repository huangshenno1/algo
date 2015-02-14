#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
return *(int *)b-*(int *)a;
}

int main()
{
int t,id,i;
int a[10];
scanf("%d",&t);
while (t--)
{
scanf("%d",&id);
for (i=0;i<10;i++)
scanf("%d",&a[i]);
qsort(a,10,sizeof(int),cmp);
printf("%d %d\n",id,a[2]);
}

return 0;
}