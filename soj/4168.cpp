#include <stdio.h>
#include <string.h>

char str[10];
int length;

bool IsPalindrome(char str[])
{
    for (int i=0;i<length/2;i++)
    {
        if (str[i]!=str[length-1-i])
            return 0;
    }
    return 1;
}

void StrToInt(char str[],int &n)
{
    n=0;
    for (int i=0;i<length;i++)
    {
        n=n*10+str[i]-48;
    }
}

void IntToStr(int n,char str[])
{
    for (int i=length-1;i>=0;i--)
    {
        str[i]=n%10+48;
        n/=10;
    }
}

int main()
{
    int i,j;
    int dis;
    int temp;
    int p;
    while (scanf("%s",str)==1)
    {
        if (!strcmp(str,"0"))
            break;
        length=strlen(str);
        if (IsPalindrome(str))
        {
            printf("0\n");
            continue;
        }
        dis=0;
        p=1;
        for (i=length-1;i>=0;i--)
        {
            if (str[i]!=str[length-1-i])
            {
                StrToInt(str,temp);
                while ((temp/p)%10!=str[length-1-i]-48)
                {
                    temp+=p;
                    dis+=p;
                    IntToStr(temp,str);
                }
            }
            p*=10;
        }
        printf("%d\n",dis);
    }
    return 0;
}