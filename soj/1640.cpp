#include <iostream>
using namespace std;

int main()
{
    int n;
    int a[60][60];
    cin>>n;
    while (n)
    {
        int i,j;
        for (i=0;i<n;i++)
        {
            for (j=0;j<n;j++)
            {
                cin>>a[i][j];
            }
        }
        i=0;
        j=0;
        while (i!=n-1||j!=n-1)
        {
            cout<<a[i][j]<<' ';
            if (!(n%2))
            {
                if ((i==0||i==n-1)&&!(j%2))
                {
                    j++;
                }
                else if (i%2&&(j==0||j==n-1))
                {
                    i++;
                }
                else
                {
                    if ((i+j)%2)
                    {
                        i++;
                        j--;
                    }
                    else
                    {
                        i--;
                        j++;
                    }
                }
            }
            else
            {
                if ((j==0&&i%2)||(j==n-1&&!(i%2)))
                {
                    i++;
                }
                else if ((i==n-1&&j%2)||(i==0&&!(j%2)))
                {
                    j++;
                }
                else
                {
                    if ((i+j)%2)
                    {
                        i++;
                        j--;
                    }
                    else
                    {
                        i--;
                        j++;
                    }
                }
            }
        }
        cout<<a[i][j]<<endl;
        cin>>n;
    }
    return 0;
}