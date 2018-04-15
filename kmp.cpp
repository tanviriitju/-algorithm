#include<bits/stdc++.h>
using namespace std;

string t;
string p;
int lps[106];//longest proper prefix
void callps()
{
    int l=p.length();
    int j=0,i=1;
    lps[0]=0;
    while(i<l)
    {
        if(p[i]==p[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                lps[i]=0;
                i++;
            }
        }
    }

}


void kmp()
{
    int len1=t.length();
    int len2=p.length();
    int i=0;//index for text
    int j=0;//index for pattern
    while(i<len1)
    {
        if(t[i]==p[j])
        {
            j++;
            i++;
        }
        else
        {
            if(j!=0)
            {
                j=lps[j-1];
            }
            else
            {
                i=i+1;
            }
        }
        if(j==len2)
        {
            pf("Match fount at %d\n",i-j);
        }
    }
}


int n,m,k;
ll N,M,K;




int main()
{
	
    int t,tc=1;
	
	    
	return 0;
}
