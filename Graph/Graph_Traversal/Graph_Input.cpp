/*/
Usually, two ways to store a graph.
1. Adjacency Matrix
2. Adjacency List

Sum of degree of edges = 2 * Sum of edges.
*/


/*
Say, a graph: 


1 2
2 3
3 4
3 5
1 3
4 5

Now we want to store it:
Using adj matrix: 

    1   2   3   4   5   
1   0   1   1   0   0
2   1   0   1   0   0
3   1   1   0   1   1
4   0   0   1   0   1
5   0   0   1   1   0

*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(void){

    ll N, M;
    cin>>N>>M;

    vector<vector<int>> adj(N+1, vector<int>(N+1, 0));     // initialized 0;
    vector<pair<int, int>> edges;

    //memset(adj, 0, sizeof adj);

    vector<int> deg(N+1, 0);

    for(int i=0; i<M; ++i){
        int u, v;
        cin>>u>>v;

        //edges.push_back({u,v});      // this is also a way to take input.

        ++adj[u][v];
        ++adj[v][u];

        ++deg[u];
        ++deg[v];
    }

    for(int i=1; i<=N; ++i){
        cout<<i<<": ";

        for(int j = 1; j<=N; ++j){
            if(adj[i][j])
                cout << j <<" ";
        }

        cout<<endl;
    }

}

