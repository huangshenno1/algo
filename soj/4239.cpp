#include <cstdio>
#include <cstring>
#include <cctype>
int ans;

int check(char str[])
{
    int a=0,b=0,c=0;
    char o;
    int i=0;
    while (!isdigit(str[i]))
        i++;
    for (;str[i]!='+'&&str[i]!='-';i++)
    {
        a=a*10+str[i]-'0';
    }
    o=str[i++];
    for (;str[i]!='=';i++)
    {
        b=b*10+str[i]-'0';
    }
    i++;
    if (str[i]=='?')
        return 0;
    for (;str[i]!='\0';i++)
    {
        c=c*10+str[i]-'0';
    }
    if (o=='+' && a+b==c)
        return 1;
    if (o=='-' && a-b==c)
        return 1;
    return 0;

}

int main()
{
    char str[100];
    ans=0;
    while (scanf("%s",str)!=EOF)
        ans+=check(str);
    printf("%d\n",ans);
    return 0;
}