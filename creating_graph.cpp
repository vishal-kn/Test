#include <bits/stdc++.h>
using namespace std;

void add_edge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void print(vector<int> adj[],int V)
{
    for(int i=0;i<V;i++)
    {
        for(int x:adj[i])
        {
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}

void bfs(vector<int> adj[], vector<int> &vis, int node, vector<int> &ans)
{
    queue<int> q;
    q.push(node);
    vis[node]=1;
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        ans.push_back(n);

        for(auto it:adj[n])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
            }
        }
    }
}
int main()
{
    int V=4;
    vector<int> adj[V];
    add_edge(adj,0,1);
    add_edge(adj,0,2);
    add_edge(adj,1,2);
    add_edge(adj,1,3);
    // print(adj,V);
    vector<int> vis(V+1,0);
    vector<int> ans;
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
        {
            bfs(adj,vis,i,ans);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    
    return 0;
}