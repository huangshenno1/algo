#include <cstdio>

int main()
{
int n;
while (~scanf("%d",&n) && n)
{
if(n%2==0)
   puts("No Solution!");
else
   printf("%d\n",n-1); 
}
return 0;
}