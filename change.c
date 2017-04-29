#include<stdio.h>
#include<malloc.h>
int** resultArray(int v,int l)
{
    int i;
    int **p=(int**)malloc(l*sizeof(int*));
    for(i=0;i<l;i++)
        p[i]=(int*)malloc((v+1)*sizeof(int));
    for(i=0;i<l;i++)
    {
        p[i][0]=0;
    }
    return p;
}
void coinchange(int amount)
{
    int l,i,j,k;
    int curr[]={1,3,5,11,13,23,101,151,193,389,587,677,881,947,997};
    printf("The currency notes available are of 1,3,5,11,13,23,101,151,193,389,587,677,881,947,997\n");
    l=sizeof(curr)/sizeof(curr[0]);

    //printf("Number of notes are %d\n",l);

    int **p=resultArray(amount,l);
    int *r;
    r=(int*)malloc(l*sizeof(int));

    /*printf("Currently array is: \n");

    for(i=0;i<l;i++)
    {
        for(j=0;j<=amount;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }*/
    k=0;
    for(i=0;i<l;i++)
    {
        for(j=1;j<=amount;j++)
        {
            if(curr[i]==1)
                p[i][j]=j;
            else if(curr[i]<=j)
            {
                //printf("curr %d j %d p[i-1][j] %d p[i][j-curr[i]+1 %d\n",curr[i],j,p[i-1][j],p[i][j-curr[i]]+1);
                if(p[i-1][j]>p[i][j-curr[i]]+1)
                {
                    p[i][j]=p[i][j-curr[i]]+1;
                    r[k]=curr[i];
                    k++;
                }
                else
                    p[i][j]=p[i-1][j];
            }
            else
            {
              p[i][j]=p[i-1][j];
            }
        }
    }
    /*printf("final array is: \n");

    for(i=0;i<l;i++)
    {
        for(j=0;j<=amount;j++)
        {
            printf("%d ",p[i][j]);
        }
        printf("\n");
    }*/
    printf("Number of Notes Dispensed are %d\n",p[l-1][amount]);

    for(i=0;i<k;i++)
    {
        printf("%d ",r[i]);
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
