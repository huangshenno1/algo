#include <stdio.h>

#define N 5842

void main()
{
    int humble[N];
    int n2,n3,n5,n7;
    int temp1,temp2;
    int i;
    int input,output;
    humble[0]=1;
    n2=n3=n5=n7=0;
    for (i=1;i<N;i++)
    {
        temp1=2*humble[n2]>3*humble[n3]?3*humble[n3]:2*humble[n2];
        temp2=5*humble[n5]>7*humble[n7]?7*humble[n7]:5*humble[n5];
        humble[i]=temp1>temp2?temp2:temp1;
        if (humble[i]==2*humble[n2]) n2++;
        if (humble[i]==3*humble[n3]) n3++;
        if (humble[i]==5*humble[n5]) n5++;
        if (humble[i]==7*humble[n7]) n7++;
    }
    scanf("%d",&input);
    while (input)
    {
        output=humble[input-1];
        if (input%100==11||input%100==12||input%100==13)
        {
            printf("The %dth humble number is %d.\n",input,output);
        }
        else if (input%10==1)
        {
            printf("The %dst humble number is %d.\n",input,output);
        }
        else if (input%10==2)
        {
            printf("The %dnd humble number is %d.\n",input,output);
        }
        else if (input%10==3)
        {
            printf("The %drd humble number is %d.\n",input,output);
        }
        else printf("The %dth humble number is %d.\n",input,output);
        scanf("%d",&input);
    }
}