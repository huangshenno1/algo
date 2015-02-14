#include <iostream>
using namespace std;

void Number(int n)
{
    switch (n)
    {
    case 0:
        cout<<"零";
        break;
    case 1:
        cout<<"壹";
        break;
    case 2:
        cout<<"贰";
        break;
    case 3:
        cout<<"叁";
        break;
    case 4:
        cout<<"肆";
        break;
    case 5:
        cout<<"伍";
        break;
    case 6:
        cout<<"陆";
        break;
    case 7:
        cout<<"柒";
        break;
    case 8:
        cout<<"捌";
        break;
    case 9:
        cout<<"玖";
        break;
    default:
        break;
    }
}

void Unit(int i)
{
    switch (i)
    {
    case 1:
        cout<<"拾";
        break;
    case 2:
        cout<<"佰";
        break;
    case 3:
        cout<<"仟";
        break;
    default:
        break;
    }
}

void RMB(int n)
{
    int num[4];
    num[3]=n/1000;
    num[2]=(n/100)%10;
    num[1]=(n/10)%10;
    num[0]=n%10;
    bool f=0;
    bool begin=0;
    for (int i=3;i>=0;i--)
    {
        if (num[i])
        {
            begin=1;
            if (f)
            {
                Number(0);
                f=0;
            }
            Number(num[i]);
            Unit(i);
        }
        else if (begin)
        {
            f=1;
        }
    }
}

int main()
{
    int n;
    cin>>n;
    for (int iCase=0;iCase<n;iCase++)
    {
        int money,upper,lower;
        cin>>money;
        if (money==0)
        {
            cout<<"零圆"<<endl;
            continue;
        }
        if (money<0)
        {
            cout<<"负";
            money=-money;
        }
        upper=money/10000;
        lower=money%10000;
        if (upper)
        {
            RMB(upper);
            cout<<"万";
        }
        if (upper&&lower&&!(lower/1000))
        {
            cout<<"零";
        }
        RMB(lower);
        cout<<"圆"<<endl;
    }
    return 0;
}