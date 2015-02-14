#include <cstdio>

int d[23]={0xb0a1,0xb0c5,0xb2c1,0xb4ee,0xb6ea,0xb7a2,0xb8c1,0xb9fe,0xbbf7,0xbfa6,0xc0ac,0xc2ac,0xc4c3,0xc5b6,0xc5be,0xc6da,0xc8bb,0xc8f6,0xcbfa,0xcdda,0xcef4,0xd1b9,0xd4d1};
char str[1000];

int main()
{
    while (scanf("%s",str)!=EOF)
    {
        for (int i=0;str[i]!='\0';i+=2)
        {
            int c=(str[i]+256)*256+str[i+1]+256;
            int j=1;
            for (;j<23;j++)
            {
                if (d[j]>c)
                    break;
            }
            if (j>=9) j++;
            if (j>=21) j+=2;
            printf("%c",'A'+j-1);
        }
        printf("\n");
    }
    return 0;
}