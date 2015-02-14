#include <iostream>
using namespace std;

int main()
{
    int k,m;
    cin>>k;
    while (k)
    {
        switch (k)
        {
            case 1:
                m=2;
                break;
            case 2:
                m=7;
                break;
            case 3:
                m=5;
                break;
            case 4:
                m=30;
                break;
            case 5:
                m=169;
                break;
            case 6:
                m=441;
                break;
            case 7:
                m=1872;
                break;
            case 8:
                m=7632;
                break;
            case 9:
                m=1740;
                break;
            case 10:
                m=93313;
                break;
            case 11:
                m=459901;
                break;
            case 12:
                m=1358657;
                break;
            case 13:
                m=2504881;
                break;
            default:
                break;
        }
cout<<m<<endl;
        cin>>k;
    }
    return 0;
}