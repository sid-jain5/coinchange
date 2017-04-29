#include<stdio.h>
#include<malloc.h>
#define INF 32500
void coinchange(int amount)
{
    int l,i,j;
    int curr[]={1,3,5,11,13,23,101,151,193,389,587,677,881,947,997};
    printf("The currency notes available are of 1,3,5,11,13,23,101,151,193,389,587,677,881,947,997\n");
    l=sizeof(curr)/sizeof(curr[0]);

    int *p=(int*)malloc(sizeof(int)*(amount+1));
    int *r;
    r=(int*)malloc((amount+1)*sizeof(int));

    for(i=0;i<=amount;i++)
    {
        if(i==0)
            p[i]=0;
        else
            p[i]=INF;

        r[i]=-1;

    }

    for(i=0;i<l;i++)
    {
        for(j=0;j<=amount;j++)
        {
            if(j>=curr[i]&&(p[j-curr[i]]+1)<p[j])
            {
                 p[j]=p[j-curr[i]]+1;
                 r[j]=i;
            }
        }
    }
    printf("Number of notes dispensed are %d\n",p[amount]);
    printf("notes dispensed are of denomination: ");
     i=amount;
     int k=36;
    while(i!=0)
    {
        printf("%c%d ",k,curr[r[i]]);
        i=i-curr[r[i]];
    }


}
int main()
{
    int amount;
    printf("Enter the amount\n");
    scanf("%d",&amount);
    coinchange(amount);
    return 0;
}
