#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll ans=0;
vector<ll>A[5000000];
ll tot=0,k;
ll subtree[2000007],del[2000007];

void dfs(ll u,ll p)
{
    tot++;
    subtree[u]=1;
    for(int i=0; i<A[u].size(); i++)
    {
        ll v=A[u][i];
        if(v==p || del[v])continue;
        dfs(v,u);
        subtree[u]+=subtree[v];
    }

}
ll getcenter(ll u,ll p)
{
    for(int i=0; i<A[u].size(); i++)
    {
        ll v=A[u][i];
        if(v==p || del[v])continue;
        if(subtree[v]>tot/2)return getcenter(v,u);
    }
    return u;
}
ll fr[2000007];
void setdist(ll u,ll p,ll cst)
{
    fr[cst]++;
    if(cst>k)return ;
    for(ll i=0; i<A[u].size(); i++)
    {
        ll v=A[u][i];
        if(v==p || del[v])continue;
        setdist(v,u,cst+1);
    }
    return ;
}
void query(ll u,ll p,ll cst)
{
   // fr[cst]++;
    if(cst>k)return ;
    ans+=fr[k-cst];
    for(ll i=0; i<A[u].size(); i++)
    {
        ll v=A[u][i];
        if(v==p || del[v])continue;
        query(v,u,cst+1);
    }
}
void dcompose(ll  u,ll p)
{
  tot =0;
  dfs(u,-1);
  ll center=getcenter(u,-1);
  for(ll i=0;i<=k;i++)fr[i]=0;
  fr[0]++;

for(ll i=0;i<A[center].size();i++)
{
    ll v=A[center][i];
    if(del[v])continue;
    query(v,center,1);
    setdist(v,center,1);
}
del[center]=1;
for(ll i=0;i<A[center].size();i++)
{
    ll v=A[center][i];
    if(del[v])continue;
    dcompose(v,center);
}


}

int main()
{
    ll n,m,i,j,l,t,r,e;
    cin>>n>>k;
    for(i=0; i<n-1; i++)
    {
        cin>>l>>r;
        A[l].push_back(r);
        A[r].push_back(l);
    }
    dcompose(1,0);
    cout<<ans<<endl;
    return 0;
}
