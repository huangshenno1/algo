#include <stdio.h>

void main()
{
    float amount;
    int s,count;
    int a,b,c,d,e,f,g,h,i;
    scanf("%f",&amount);
    while (amount!=0)
    {
        s=amount*100;
        count=0;
        for (a=s/5000;a>=0;a--)
            for (b=(s-a*5000)/2000;b>=0;b--)
                for (c=(s-a*5000-b*2000)/1000;c>=0;c--)
                    for (d=(s-a*5000-b*2000-c*1000)/500;d>=0;d--)
                        for (e=(s-a*5000-b*2000-c*1000-d*500)/200;e>=0;e--)
                            for (f=(s-a*5000-b*2000-c*1000-d*500-e*200)/100;f>=0;f--)
                                for (g=(s-a*5000-b*2000-c*1000-d*500-e*200-f*100)/50;g>=0;g--)
                                    for (h=(s-a*5000-b*2000-c*1000-d*500-e*200-f*100-g*50)/20;h>=0;h--)
                                        for (i=(s-a*5000-b*2000-c*1000-d*500-e*200-f*100-g*50-h*20)/10;i>=0;i--)
                                            count++;
        printf("%5.2f%12d\n",amount,count);                
        scanf("%f",&amount);
    }
}

