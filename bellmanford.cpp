
#include<bits/stdc++.h>
using namespace std;

#define SET(a) memset(a,-1,sizeof(a))
#define CLR(a) memset(a,0,sizeof(a))
#define PI acos(-1.0)

#define MOD 1000000007
#define MX 2000


struct Z{
    int a,b,cost;
} eg[MX+5];

bool BellmanFord(int n, int m)  //n=node, m=edge
{
    int cost[n+5];
    bool negativeCycle=false;

    cost[0]=0;
    for(int i=1; i<n; i++)   cost[i]=1e9;

    for(int i=0; i<n-1; i++)
        for(int j=0; j<m; j++)
            if(cost[eg[j].b]>cost[eg[j].a]+eg[j].cost)
                cost[eg[j].b]=cost[eg[j].a]+eg[j].cost;  //find minimum cost to reach all node from source


    for(int i=0; i<m; i++)
        if(cost[eg[i].b]>cost[eg[i].a]+eg[i].cost)  //less than minimum possible?
            negativeCycle=true;

return negativeCycle;
}

int main()
{
    int tc, n, m;
    cin>>tc;
    while(tc--)
    {
        cin>>n>>m;


        for(int i=0; i<m; i++)
            cin>>eg[i].a>>eg[i].b>>eg[i].cost;

        if(BellmanFord(n, m))
            cout<<"possible"<<endl;
        else
            cout<<"not possible"<<endl;

    }
    return 0;
}
