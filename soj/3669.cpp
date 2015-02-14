#include <cstdio>
#include <cstring>

char hex[100010],oct[140000];
int l,k;

int toInt(char c)
{
    if (c>'9') return c-'A'+10;
    return c-'0';
}

void toOct(int n)
{
    int temp[5]={0},i=0;
    while (n)
    {
        temp[i++]=n%8;
        n/=8;
    }
    for (i=3;i>=0;i--) oct[k++]=temp[i]+'0';
}

int main()
{
    int i,j,s;
    while (scanf("%s",hex)==1)
    {
        if(hex[0]=='0')
        {
            printf("0\n");
            continue;
        }

        l=strlen(hex);
        k=0;

        i=l%3;
        for (s=j=0;j<i;j++)
            s=s*16+toInt(hex[j]);
        toOct(s);

        for (;i<l;i+=3)
        {
            for (s=j=0;j<3;j++)
                s=s*16+toInt(hex[i+j]);
            toOct(s);
        }

        oct[k]='\0';
        for (i=0;i<k;i++)
            if (oct[i]!='0') break;
        printf("%s\n",oct+i);
    }
    return 0;
}