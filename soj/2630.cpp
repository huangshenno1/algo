#include <stdio.h>
#include <string.h>

int main()
{
    char octopus[10];
    scanf("%s",octopus);
    while (octopus[0]!='#')
    {
        int decimal=0;
        int length=strlen(octopus);
        for (int i=0;i<length;i++)
        {
            int d=0;
            switch (octopus[i])
            {
            case '-':
                d=0;
                break;
            case '\\':
                d=1;
                break;
            case '(':
                d=2;
                break;
            case '@':
                d=3;
                break;
            case '?':
                d=4;
                break;
            case '>':
                d=5;
                break;
            case '&':
                d=6;
                break;
            case '%':
                d=7;
                break;
            case '/':
                d=-1;
                break;
            default:
                break;
            }
            decimal=decimal*8+d;
        }
        printf("%d\n",decimal);
        scanf("%s",octopus);
    }
    return 0;
}