//高精度运算
#include <cstring>

//反转
void bigreverse(char a[])
{
	int l = strlen(a);
	for (int i = 0; i < l/2; i++)
	{
		char temp = a[i];
		a[i] = a[l-i-1];
		a[l-i-1] = temp;
	}
}

//判断反转后符号并去掉符号，正数为0，负数为1
bool bigflag(char a[])
{
	int l = strlen(a);
	if (a[l-1] == '-') {a[l-1] = '\0'; return 1;}
	if (a[l-1] == '+') a[l-1] = '\0';
	return 0;
}

//去反转后的前导零
void bignoleadingzero(char a[])
{
	for (int i = strlen(a)-1; i>0 && a[i] == 48; i--)
		a[i] = '\0';
}

//加法
void bigsum(char a[], char b[], char c[])
{
	int la = strlen(a);
	int lb = strlen(b);
	int lc, carry = 0;
	for (lc = 0; a[lc]!='\0' && b[lc]!='\0'; lc++)
	{
		c[lc] = (a[lc] - 48) + (b[lc] - 48) + carry;
		carry = c[lc] / 10;
		c[lc] = c[lc] % 10 + 48;
	}
	while (lc < la)
	{
		c[lc] = (a[lc] - 48) + carry;
		carry = c[lc] / 10;
		c[lc] = c[lc] % 10 + 48;
		lc++;
	}
	while (lc < lb)
	{
		c[lc] = (b[lc] - 48) + carry;
		carry = c[lc] / 10;
		c[lc] = c[lc] % 10 + 48;
		lc++;
	}
	if (carry) c[lc++] = carry + 48;
	c[lc] = '\0';
	bignoleadingzero(c);
}

//乘法
void bigmul(char a[], char b[], char c[])
{
	int la = strlen(a);
	int lb = strlen(b);
	int i, j, carry;
	for (i = 0; i < la+lb; i++) c[i] = 48;
	for (i = 0; i < la; i++)
	{
		carry = 0;
		for (j = 0; j < lb; j++)
		{
			c[i+j] = (c[i+j] - 48) + (a[i] - 48)*(b[j] - 48) + carry;
			carry = c[i+j] / 10;
			c[i+j] = c[i+j] % 10 + 48;
		}
		if (carry) c[i+j] = c[i+j] + carry;
	}
	int lc = i+j;
	if (!carry) lc--;
	c[lc] = '\0';
	bignoleadingzero(c);
}

//比较大小
int bigcmp(char a[], char b[])
{
	int la = strlen(a);
	int lb = strlen(b);
	if (la > lb) return 1;
	if (la < lb) return -1;
	for (int i = la-1; i >= 0; i--)
	{
		if (a[i] > b[i]) return 1;
		if (a[i] < b[i]) return -1;
	}
	return 0;
}

//交换
void bigswap(char a[], char b[])
{
	char c[maxn];
	strcpy(c, a);
	strcpy(a, b);
	strcpy(b, c);
}

//减法
void bigsub(char a[], char b[], char c[])
{
	int la = strlen(a);
	int lb = strlen(b);
	int lc, carry = 0;
	for (lc = 0; a[lc]!='\0' && b[lc]!='\0'; lc++)
	{
		c[lc] = 48 + a[lc] - b[lc] - carry;
		if (c[lc] < 48) {carry = 1; c[lc] += 10;}
		else carry = 0;
	}
	while (lc < la)
	{
		c[lc] = a[lc] - carry;
		if (c[lc] < 48) {carry = 1; c[lc] += 10;}
		else carry = 0;
		lc++;
	}
	c[lc] = '\0';
	bignoleadingzero(c);
}