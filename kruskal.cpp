#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define inf (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define all(a) a.begin(),a.end()
#define clr(a) memset(a,0,sizeof(a))
#define fill(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define pi acos(-1.0)
#define eps 1e-9


long long P[200000+5],rank[200000+5];


struct Node{
    long long a,b,c;
    bool operator < (const Node &p) const{
    return c>p.c;
    }
};

int FIND(int x)
{
    if(x==P[x]) return x;
    else
    return P[x]=FIND(P[x]);
}

void UNION(int a,int b)
{
        P[a]=FIND(b);

}
Node nd;

int main()
{
    int tc,i,j,m,n,cnt,A,B,PA,PB,start,end,doller;
    long long Cost,Tcost,totalCost;
    priority_queue<Node>pq;

    while(cin>>m>>n)
    {

        if(m==0 && n==0)
        break;
        totalCost=0;
        cnt=0;
        Tcost=0;
        while(!pq.empty())
        pq.pop();
        for(i=0;i<n;i++)
            {
                cin>>start>>end>>doller;
                P[i]=i;
                nd.a=start;
                nd.b=end;
                nd.c=doller;
                totalCost+=doller;
                pq.push(nd);
            }



        while(!pq.empty())
            {
                if(cnt==m-1) break;
                A=pq.top().a;
                B=pq.top().b;
                Cost=pq.top().c;
                PA=FIND(A);
                PB=FIND(B);
                if(PA!=PB)
                    {
                        Tcost+=Cost;
                        cnt++;
                        UNION(PA,PB);
                    }
                pq.pop();

            }


    cout<<totalCost-Tcost;

    cout<<endl;

    }
return 0;
}
