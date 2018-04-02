#include<bits/stdc++.h>
using namespace std;
vector <int> g[100002],cost[100002];
struct node
{
    int u,w;
    node(int a,int b)
    {
        u=a;
        w=b;
    }
    bool operator<(const node&p)const
    {
        return w>p.w;
    }
};
int d[100002],par[100002];
void dijkstra(int n)
{
    memset(d,20001,sizeof(d));
    memset(par,-1,sizeof(par));
    priority_queue<node>q;
    q.push(node(n,0));
    d[n]=0;
    while(!q.empty())
    {
        node top=q.top();
        q.pop();
        int u=top.u;
        // if(u==n)return d[n];
        for(int i=0; i<(int)g[u].size(); i++)
        {
            int v=g[u][i];
            if(max(d[u],cost[u][i])<d[v])
            {
                d[v]=max(d[u],cost[u][i]);
                par[v]=u;
                q.push(node(v,d[v]));
            }
        }
    }
    //return -1;
}
int main()
{
    int n,i,j,k,l,t,r,e,m;
    scanf("%d",&t);
    for(l=1; l<=t; l++)
    {
 
r=0;
        scanf("%d %d",&n,&e);
        for(i=0; i<e; i++)
        {
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            r=max(r,w);
            g[u].push_back(v);
            g[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        scanf("%d",&m);
        dijkstra(m);
        printf("Case %d:\n",l);
        for(j=0; j<n; j++)
        {
            if(d[j]>r)printf("Impossible\n");
            else
                printf("%d\n",d[j]);
        }
        memset(g,0,sizeof(g));
        memset(cost,0,sizeof(cost));
 
    }
    return 0;
}
