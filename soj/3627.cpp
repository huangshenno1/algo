#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int t,l,a,c,ac,i,j,ans;
char str[20];
char wrong[6][5]={"WA","TLE","RE","CE","OLE","PE"};
int wl[6]={2,3,2,2,3,2};

bool like()
{
    int i;
    for(i=1;i<l;i++)
        if(str[i] =='E' && (str[i-1]=='R'||str[i-1]=='P'||str[i-1]=='C'||str[i-1]=='Z'))
            return 0;
    for(i=1;i<l;i++)
        if(str[i-1]=='W' && (str[i] =='Z'||str[i]=='A'))
            return 0;
    for(i=2;i<l;i++)
        if(str[i-1] == 'L'&&str[i] == 'E'&& (str[i-2]=='T' || str[i-2]=='O'))
            return 0;
    return 1;
}

int main()
{
    scanf("%d",&t);
    getchar();
    while (t--)
    {
        ans=0;
        scanf("%s",str);
        l=strlen(str);
        a=c=0;
        for (i=0;i<l;i++)
        {
            if (str[i]=='A') a++;
            if (str[i]=='C') c++;
        }
        ac=min(a,c);
        a=c=ac;
        for (i=0;i<l;i++)
        {
            if (str[i]=='A' && a>0) str[i]='Z',a--;
            if (str[i]=='C' && c>0) str[i]='Z',c--;
        }
        sort(str,str+l);
        l-=ac;
        str[l]='\0';
        do
        {
            if (like())
                ans++;
        }while (next_permutation(str,str+l));
        printf("%d\n",ans);
    }
    return 0;
}