#include <stdio.h>
#include <string.h>

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int n;
        scanf("%d",&n);
        if (n<=1)
            printf("1\n");
        else
        {
            char fac[36000]="1";
            int l=1;
            for (int i=2;i<=n;i+=2)
            {
                int factor;
                if (i==n)
                    factor=n;
                else factor=i*(i+1);
                int carry=0;
                for (int j=0;j<l;j++)
                {
                    int temp=(fac[j]-'0')*factor+carry;
                    carry=temp/10;
                    fac[j]=temp%10+'0';
                }
                while (carry)
                {
                    fac[l++]=carry%10+'0';
                    carry=carry/10;
                }
                fac[l]='\0';
            }
            for (int i=0;i<l/2;i++)
            {
                char temp=fac[i];
                fac[i]=fac[l-1-i];
                fac[l-1-i]=temp;
            }
            printf("%s\n",fac);
        }
    }
    return 0;
}