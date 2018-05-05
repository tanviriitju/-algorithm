#include<stdio.h>
#include<string.h>
#define max 1002
#define len 2600
int fact[max][len];
void factorial()
{
   fact[0][0]=1;
    fact[1][0]=1;
   int i,j,k;
   for(i=2;i<max;i++)
   {
       for(j=0;j<len;j++)
       {
           fact[i][j] = fact[i][j] + fact[i-1][j]*i;
           if(fact[i][j]>9)
           {
               fact[i][j+1] = fact[i][j]/10;
               fact[i][j] = fact[i][j]%10;
           }
       }
   }
}
int main()
{
    factorial();
    int i,j,k,n;

    while(scanf("%d",&n)==1)
    {
        printf("%d!\n",n);
        for(i=len-1;i>=0;i--)
        {
            if(fact[n][i]!=0)
                break;
        }

        for(j=i;j>=0;j--)
        {
            printf("%d",fact[n][j]);
        }
        printf("\n");

    }

    return 0;
}
