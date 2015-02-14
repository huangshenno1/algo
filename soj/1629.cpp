#include <iostream>
using namespace std;

int main()
{
    int a1,b1,a2,b2,a3,b3;
    cin>>a1>>b1>>a2>>b2>>a3>>b3;
    while (a1||a2||a3||b1||b2||b3)
    {
        int game=(a1+a2+a3+b1+b2+b3)/3;
        int win=b1+b2+b3-game;
        int lose=a1+a2+a3-game;
        cout<<win<<'-'<<lose<<endl;
        cin>>a1>>b1>>a2>>b2>>a3>>b3;
    }
    return 0;
}