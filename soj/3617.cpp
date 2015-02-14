#include <stdio.h>

int main()
{
int t;
int a,b,c;
printf("Gnomes:\n");
scanf("%d",&t);
while (t--)
{
    scanf("%d%d%d",&a,&b,&c);
    if ((a<b&&b<c) || (a>b&&b>c))
        printf("Ordered\n");
    else printf("Unordered\n");
}
return 0;
}