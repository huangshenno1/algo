#include <stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    for (int iCase=0;iCase<n;iCase++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if ((a%2)!=(b%2)||a<0||b<0||a<b)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%d %d\n",(a+b)/2,(a-b)/2);
        }
    }
    return 0;
}