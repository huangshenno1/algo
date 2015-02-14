#include <stdio.h>

bool IsPalindrome(int n)
{
    int digit[12];
    int length=0;
    bool flag=1;
    while (n)
    {
        digit[length++]=n%10;
        n/=10;
    }
    for (int i=0;i<length/2;i++)
    {
        if (digit[i]!=digit[length-1-i])
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int main()
{
    int n;
    scanf("%d",&n);
    while (n)
    {
        if (IsPalindrome(n))
            printf("yes\n");
        else printf("no\n");
        scanf("%d",&n);
    }
    return 0;
}