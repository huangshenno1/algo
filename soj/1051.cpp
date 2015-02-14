#include <cstdio>
#include <cstring>

const char lmap[26]={'A','-','-','-','3','-','-','H','I','L','-','J','M','-','O','-','-','-','2','T','U','V','W','X','Y','5'};
const char nmap[10]={'-','1','S','E','-','Z','-','-','8','-'};

bool IsPalindrome(char *str)
{
    int l=strlen(str);
    for (int i=0;i<l/2;i++)
    {
        if (str[i]!=str[l-1-i])
            return 0;
    }
    return 1;
}

bool IsMirror(char *str)
{
    int l=strlen(str);
    for (int i=0;i<=l/2;i++)
    {
        if (str[i]>='A'&&str[i]<='Z')
        {
            if (lmap[str[i]-'A']!=str[l-1-i])
                return 0;
        }
        else
        {
            if (nmap[str[i]-'0']!=str[l-1-i])
                return 0;
        }
    }
    return 1;
}

int main()
{
    char str[25];
    bool flag1,flag2;
    while (scanf("%s",str)==1)
    {
        flag1=IsPalindrome(str);
        flag2=IsMirror(str);
        if (flag1&&flag2)
            printf("%s -- is a mirrored palindrome.\n",str);
        if (flag1&&!flag2)
            printf("%s -- is a regular palindrome.\n",str);
        if (flag2&&!flag1)
            printf("%s -- is a mirrored string.\n",str);
        if (!flag1&&!flag2)
            printf("%s -- is not a palindrome.\n",str);
        printf("\n");
    }
    return 0;
}