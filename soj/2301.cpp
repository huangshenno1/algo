//高精度运算
#include <cstdio>
#include <cstring>

const int maxn = 20000;

//反转
void reverse(char a[])
{
    int l = strlen(a);
    for (int i = 0; i < l/2; i++)
    {
        char temp = a[i];
        a[i] = a[l-i-1];
        a[l-i-1] = temp;
    }
}

//判断反转后符号并去掉符号，正数为0，负数为1
bool bigflag(char a[])
{
    int l = strlen(a);
    if (a[l-1] == '-') {a[l-1] = '\0'; return 1;}
    if (a[l-1] == '+') a[l-1] = '\0';
    return 0;
}

//去反转后的前导零
void noleadingzero(char a[])
{
    for (int i = strlen(a)-1; i>0 && a[i] == 48; i--)
        a[i] = '\0';
}

//加法
void bigsum(char a[], char b[], char c[])
{
    int la = strlen(a);
    int lb = strlen(b);
    int lc, carry = 0;
    for (lc = 0; a[lc]!='\0' && b[lc]!='\0'; lc++)
    {
        c[lc] = (a[lc] - 48) + (b[lc] - 48) + carry;
        carry = c[lc] / 10;
        c[lc] = c[lc] % 10 + 48;
    }
    while (lc < la)
    {
        c[lc] = (a[lc] - 48) + carry;
        carry = c[lc] / 10;
        c[lc] = c[lc] % 10 + 48;
        lc++;
    }
    while (lc < lb)
    {
        c[lc] = (b[lc] - 48) + carry;
        carry = c[lc] / 10;
        c[lc] = c[lc] % 10 + 48;
        lc++;
    }
    if (carry) c[lc++] = carry + 48;
    c[lc] = '\0';
    noleadingzero(c);
}

//比较大小
int bigcmp(char a[], char b[])
{
    int la = strlen(a);
    int lb = strlen(b);
    if (la > lb) return 1;
    if (la < lb) return -1;
    for (int i = la-1; i >= 0; i--)
    {
        if (a[i] > b[i]) return 1;
        if (a[i] < b[i]) return -1;
    }
    return 0;
}

//交换
void bigswap(char a[], char b[])
{
    char c[maxn];
    strcpy(c, a);
    strcpy(a, b);
    strcpy(b, c);
}

//减法
void bigsub(char a[], char b[], char c[])
{
    int la = strlen(a);
    int lb = strlen(b);
    int lc, carry = 0;
    for (lc = 0; a[lc]!='\0' && b[lc]!='\0'; lc++)
    {
        c[lc] = 48 + a[lc] - b[lc] - carry;
        if (c[lc] < 48) {carry = 1; c[lc] += 10;}
        else carry = 0;
    }
    while (lc < la)
    {
        c[lc] = a[lc] - carry;
        if (c[lc] < 48) {carry = 1; c[lc] += 10;}
        else carry = 0;
        lc++;
    }
    c[lc] = '\0';
    noleadingzero(c);
}

int main()
{
    char a[maxn],b[maxn],c[maxn];
    bool flag;
    while (scanf("%s%s",a,b)==2)
    {
        flag = 1;
        reverse(a); reverse(b);
        flag=flag^bigflag(a)^bigflag(b);
        noleadingzero(a); noleadingzero(b);
        if (flag)
        {
            if (bigcmp(a,b)==-1) bigswap(a,b);
            bigsub(a,b,c);
        }
        else
        {
            bigsum(a,b,c);
        }
        reverse(c);
        printf("%s\n",c);
    }
    return 0;
}