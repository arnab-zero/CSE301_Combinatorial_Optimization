#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
typedef long long ll;

int main(void){
    ll n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i=0; i<m; ++i){
        int u, v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> q;
    vi dis(n+1, INT_MAX), vis(n+1, INT_MAX);

    q.push(1);
    vis[1] = 1;
    dis[1] = 0;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        
        for(auto v: adj[u]){
            if(vis[v])
                continue;
            vis[v] = 1;
            dis[v] = dis[u] + 1;
            q.push(v);
        }
    }

    for(int i=1; i<=n; ++i){
        cout<<i<<" "<<dis[i]<<endl;
    }

    return 0;
}

