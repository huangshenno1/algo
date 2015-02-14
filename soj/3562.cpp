#include <stdio.h>
#include <string.h>

int main()
{
int t;
bool map[7][7];
int a,b,c;
int i,j;
scanf("%d",&t);
while (t--)
{
memset(map,0,sizeof(map));
for (i=1;i<=6;i++)
map[i][i]=1;
for (i=0;i<8;i++)
{
scanf("%d%d%d",&a,&b,&c);
map[a][b]=map[b][a]=map[a][c]=map[c][a]=map[b][c]=map[c][b]=1;
}
for (i=1;i<=6;i++)
{
for (j=1;j<=6;j++)
{
if (map[i][j]==0)
{
printf("%d",j);
break;
}
}
if (i<6)
printf(" ");
else printf("\n");
}
}
return 0;
}