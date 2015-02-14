#include <stdio.h>

int main()
{
    int n;
    int ans;
    while (scanf("%d",&n)==1)
    {
        if (n==4||n==7)
        {
            printf("-1\n");
            continue;
        }
        ans=n/15;
        ans=ans*3;
        n=n%15;
        if (n==1 || n==3 || n==5)
            ans+=1;
        if (n==2 || n==4 || n==6 ||n==8 ||n==10)
            ans+=2;
        if (n==7 || n==9 ||n==11 ||n==13)
            ans+=3;
        if (n==12 || n==14)
            ans+=4;
        printf("%d\n",ans);
    }
}