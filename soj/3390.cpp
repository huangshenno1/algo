#include <cstdio>

int main()
{
    int T,t;
    char str[100],dic[30];
    scanf("%d",&T);
    getchar();
    for (t=1;t<=T;t++)
    {
        gets(str);
        gets(dic);
        for (int i=0;str[i]!='\0';i++)
        {
            if (str[i]>='A' && str[i]<='Z')
                str[i]=dic[str[i]-'A'];
        }
        printf("%d ",t);
        puts(str);
    }
    return 0;
}