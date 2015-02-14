#include <stdio.h>
#include <string.h>

int main()
{
    char current[15];
    long long input;
    scanf("%s",current);
    int l=strlen(current);
    while (scanf("%lld",&input)==1)
    {
        for (int i=l-1;i>=0;i--)
        {
            current[i]=(current[i]-'0'+input%10)%10+'0';
            input/=10;
        }
    }
    printf("%s\n",current);
    return 0;
}