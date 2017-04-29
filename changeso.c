#include<stdio.h>
#include<malloc.h>
long long int** resultArray(long long int v,long long int l)
{
    long long int i;
    long long int **p=(long long int**)malloc(2*sizeof(long long int*));
    for(i=0;i<2;i++)
       {
           p[i]=(long long int*)malloc((v+1)*sizeof(long long int));
           if(p[i]==NULL)
            printf("unable to allocate memory\n");
       }
    for(i=0;i<2;i++)
    {
        p[i][0]=0;
    }
    return p;
}
void coinchange(long long int amount)
{
    long long int l,i,j,b;
    long long int curr[]={1,3,5,11,13,23,101,151,193,389,587,677,881,947,997,998};
    printf("The currency notes available are of 1,3,5,11,13,23,101,151,193,389,587,677,881,947,997\n");
    l=sizeof(curr)/sizeof(curr[0]);

    printf("Number of notes are %lld\n",l);

    long long int **p=resultArray(amount,l);
    //long long int *r;
    //r=(long long int*)malloc(l*sizeof(long long int));

    /*prlong long intf("Currently array is: \n");

    for(i=0;i<l;i++)
    {
        for(j=0;j<=amount;j++)
        {
            prlong long intf("%lld ",p[i][j]);
        }
        prlong long intf("\n");
    }*/
    //k=0;
    b=1;
    for(i=0;i<l;i++)
    {
        b=b==0?1:0;
        //prlong long intf("value of b is %lld",b);
        for(j=1;j<=amount;j++)
        {
            if(curr[i]==1)
                p[b][j]=j;
            else if(curr[i]<=j)
            {
                //prlong long intf("curr %lld j %lld p[i-1][j] %lld p[i][j-curr[i]+1 %lld\n",curr[i],j,p[i-1][j],p[i][j-curr[i]]+1);
                if(p[1-b][j]>p[b][j-curr[i]]+1)
                {
                    p[b][j]=p[b][j-curr[i]]+1;
                    /*r[k]=curr[i];
                    k++;*/
                }
                else
                    p[b][j]=p[1-b][j];
            }
            else
            {
              p[b][j]=p[1-b][j];
            }
        }
    }
    /*printf("final array is: \n");

    for(i=0;i<l;i++)
    {
        for(j=0;j<=amount;j++)
        {
            printf("%lld ",p[i][j]);
        }
        printf("\n");
    }*/
    printf("Number of Notes Dispensed are %lld\n",p[b][amount]);
    return;
    /*for(i=0;i<k;i++)
    {
        prlong long intf("%lld ",r[i]);
    }*/

}
int main()
{
    long long int amount;
    printf("Enter the amount\n");
    scanf("%lld",&amount);
    coinchange(amount);
    return 0;
}
