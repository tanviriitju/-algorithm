#include<bits/stdc++.h>
using namespace std;

char fib[5000][2000];

char fibo()
{
    fib[0][0]='0';
    fib[1][0]='1';
    fib[2][0]='1';
    fib[0][1]=fib[1][1]=fib[2][1]='\0';
    for(int i=3;i<=5000;i++)
    {
        int j=0;
        int carry=0;
        while(fib[i-1][j]!='\0' && fib[i-2][j]!='\0')
        {
            fib[i][j]=(fib[i-1][j]-'0'+fib[i-2][j]-'0'+carry)%10 +'0';
            carry=(fib[i-1][j]-'0'+fib[i-2][j]-'0'+carry)/10;
            j++;
        }
        while(fib[i-1][j]!='\0')
        {
            fib[i][j]=(fib[i-1][j]-'0'+carry)%10 +'0';
            carry=(fib[i-1][j]-'0'+carry)/10;
            j++;
        }
        if(carry)fib[i][j++]='1';
        fib[i][j]='\0';

    }
}






int i,j,k,m,n,a,b,c,tc,o,ans,q,x,y;

char s[100099],com[109];

int main()
{
    fibo();
   scanf("%d",&i);

        j=strlen(fib[i]);
        for(j--;j>=0;j--)printf("%c",fib[i][j]);
   printf("\n");


    return 0;
}
