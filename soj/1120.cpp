#include <iostream>
using namespace std;

bool binary[8000];
int N;
int k=0;

void ConvertToBinary(int n)
{
    binary[k++]=n/128;
    n=n%128;
    binary[k++]=n/64;
    n=n%64;
    binary[k++]=n/32;
    n=n%32;
    binary[k++]=n/16;
    n=n%16;
    binary[k++]=n/8;
    n=n%8;
    binary[k++]=n/4;
    n=n%4;
    binary[k++]=n/2;
    n=n%2;
    binary[k++]=n;
}

void ConvertToDecimal()
{
    int count=1;
    bool flag=binary[0];
    for (int i=1;i<N;i++)
    {
        if (binary[i]==binary[i-1])
        {
            count++;
            if (i==N-1)
                cout<<count+flag*128;
        }
        else
        {
            if (i==N-1)
                cout<<count+flag*128<<' '<<128*flag+1;
            else cout<<count+flag*128<<' ';
            count=1;
            flag=!flag;
        }
    }
}



int main()
{
    cin>>N;
    int n;
    for (int i=0;i<N/8;i++)
    {
        cin>>n;
        ConvertToBinary(n);
    }
    ConvertToDecimal();
    return 0;
}