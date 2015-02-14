#include <cstdio>
#include <cstring>

bool f[8010];
bool ans[22];
int A,B,C;

int Min(int a,int b) {return a<b?a:b;}
int toInt(int a,int b,int c) {return a*400+b*20+c;}

void next(int a,int b,int c)
{
    if (f[toInt(a,b,c)]) return;
    f[toInt(a,b,c)]=1;
    if (a==0) ans[c]=1;

    int d;
    d=Min(a,B-b); next(a-d,b+d,c);
    d=Min(a,C-c); next(a-d,b,c+d);
    d=Min(b,A-a); next(a+d,b-d,c);
    d=Min(b,C-c); next(a,b-d,c+d);
    d=Min(c,A-a); next(a+d,b,c-d);
    d=Min(c,B-b); next(a,b+d,c-d);
}

int main()
{
    while (scanf("%d%d%d",&A,&B,&C)==3)
    {
        //if (c<=a&&c<=b) {printf("0 %d\n",c); continue;}

        memset(f,0,sizeof(f));
        memset(ans,0,sizeof(ans));
        next(0,0,C);

        for (int first=1, i=0;i<=20;i++)
        {
            if (ans[i])
            {
                if (!first) printf(" ");
                else first=0;
                printf("%d",i);
            }
        }
        printf("\n");
    }
    return 0;
}