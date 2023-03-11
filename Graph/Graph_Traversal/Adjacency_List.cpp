#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){

/*
adj[1] = {2,3};
or, adj[1] = {(2,w), (3,w)};  -- store as pairs, when weight is enclosed.
*/

    ll n, m;
    cin>> n>> m;

    // vector<int> adj[n+1];
    vector<vector<int>> adj(n+1);

    for(int i=0; i<m; ++i){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1; i<=n; ++i){
        cout<<i<<": ";
        for(auto v: adj[i]){
            cout<<v<<" ";
        }
        cout<<endl;
    }

    return 0;
}