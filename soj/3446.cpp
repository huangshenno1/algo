#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<memory.h>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int ans=0;
        int num;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&num);
            if(num%4==0) ans^=(num-1);
            else if(num%4==2||num%4==1) ans^=num;
            else  ans^=(num+1);
        }
        if(ans!=0) puts("Alice");
        else puts("Bob");
    }
}
