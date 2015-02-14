#include <stdio.h>

int main()
{
int a[30];
int b;
int n,t,i;
while (scanf("%d",&n)==1&&n)
{
b=0;
scanf("%d",&a[0]);
for (i=1;i<n;i++)
{
scanf("%d",&t);
if (t!=a[b])
a[++b]=t;
}
for (i=0;i<=b;i++)
printf("%d ",a[i]);
printf("$\n");
}
return 0;
}