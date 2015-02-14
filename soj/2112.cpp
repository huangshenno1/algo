#include <cstdio>

int w,l;

char str[10000];

void Init()
{
    w=l=0;
}

void Update(int win)
{
    if ((w>=win && w-l>1) || (l>=win && l-w>1))
    {
        printf("%d:%d\n",w,l);
        Init();
    }
}


int main()
{
    char c;
    int i=0;
    while ((c=getchar())!=EOF)
    {
        if (c=='E' || c=='W' || c=='L')
            str[i++]=c;
    }
    for (i=0;str[i]!='\0';i++)
    {
        if (str[i]=='E')
            break;
        if (str[i]=='W')
            w++;
        if (str[i]=='L')
            l++;
        Update(11);
    }
    if (w||l)
        printf("%d:%d\n\n",w,l);
    Init();
    for (i=0;str[i]!='\0';i++)
    {
        if (str[i]=='E')
            break;
        if (str[i]=='W')
            w++;
        if (str[i]=='L')
            l++;
        Update(21);
    }
    if (w||l)
        printf("%d:%d\n",w,l);
    return 0;
}