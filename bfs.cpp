
#include<bits/stdc++.h>
#include<vector>
#include<queue>
using namespace std;
vector<int>vc[1000];
int dis[100000],s,vis[100000];
void bfs()
{
    int i,j,k,l;
    queue<int > q;
    vis[s]=1;
    q.push(s);
    while(!q.empty())
    {
        k=q.front();
        q.pop();
        for(i=0; i<vc[k].size(); i++)
        {
            l=vc[k][i];
            if(vis[l]==0)
            {
                vis[l]=1;
                dis[l]=dis[k]+1;
                q.push(l);
            }
        }
    }
}
int main()
{
    int n,i,j,k,l,t,r,e,w,u=1,a=1;
    while(scanf("%d",&n)==1)
    {
        for(i=0; i<n; i++)
        {
            scanf("%d",&k);

            vc[u].push_back(k);
            vc[k].push_back(u);
        }
        u++;
        if(u==20)
        {
            u=1;

            scanf("%d",&t);
             printf("Test Set #%d\n",a++);
            for(j=0; j<t; j++)
            {
                scanf("%d %d",&s,&e);
                bfs();
                printf("%2d to %2d: %d\n",s,e,dis[e]);
                memset(dis,0,sizeof(dis));
                memset(vis,0,sizeof(vis));
            }
                printf("\n");
            memset(vc,0,sizeof(vc));

        }
    }
    return 0;
}
