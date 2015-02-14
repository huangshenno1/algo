#include <cstdio>

int main()
{
    int a[7];
    int count;
    int r;
    while (scanf("%d%d%d%d%d%d",&a[1],&a[2],&a[3],&a[4],&a[5],&a[6])==6 && !(a[1]==0&&a[2]==0&&a[3]==0&&a[4]==0&&a[5]==0&&a[6]==0))
    {
        count=0;
        if (a[6])
        {
            count+=a[6];
            a[6]=0;
        }
        if (a[5])
        {
            count+=a[5];
            r=11*a[5];
            if (a[1]<r)
                a[1]=0;
            else a[1]-=r;
            a[5]=0;
        }
        if (a[4])
        {
            count+=a[4];
            r=20*a[4];
            if (a[2]*4<r)
            {
                r-=a[2]*4;
                a[2]=0;
                if (a[1]<r)
                    a[1]=0;
                else a[1]-=r;
            }
            else a[2]-=r/4;
            a[4]=0;
        }
        if (a[3])
        {
            count+=(a[3]+3)/4;
            if (a[3]%4!=0)
            {
                r=36-9*(a[3]%4);
                if (a[3]%4==1)
                {
                    if (a[2]<5)
                    {
                        r-=a[2]*4;
                        a[2]=0;
                        if (a[1]<r)
                            a[1]=0;
                        else a[1]-=r;
                    }
                    else
                    {
                        r-=20;
                        a[2]-=5;
                        if (a[1]<r)
                            a[1]=0;
                        else a[1]-=r;
                    }
                }
                else if (a[3]%4==2)
                {
                    if (a[2]<3)
                    {
                        r-=a[2]*4;
                        a[2]=0;
                        if (a[1]<r)
                            a[1]=0;
                        else a[1]-=r;
                    }
                    else
                    {
                        r-=12;
                        a[2]-=3;
                        if (a[1]<r)
                            a[1]=0;
                        else a[1]-=r;
                    }
                }
                else
                {
                    if (a[2]<1)
                    {
                        r-=a[2]*4;
                        a[2]=0;
                        if (a[1]<r)
                            a[1]=0;
                        else a[1]-=r;
                    }
                    else
                    {
                        r-=4;
                        a[2]-=1;
                        if (a[1]<r)
                            a[1]=0;
                        else a[1]-=r;
                    }
                }
            }
            a[3]=0;
        }
        if (a[2])
        {
            count+=(a[2]+8)/9;
            if (a[2]%9!=0)
            {
                r=36-4*(a[2]%9);
                if (a[1]<r)
                    a[1]=0;
                else a[1]-=r;
            }
            a[2]=0;
        }
        if (a[1])
        {
            count+=(a[1]+35)/36;
            a[1]=0;
        }
        printf("%d\n",count);
    }
    return 0;
}