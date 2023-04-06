#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define spc " "
#define tab "\t"
typedef long long int lli;

priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<bool> vis(100, false);       // marks if a vertex is already visited or not

void mst_prim(vector< vector<pair<int, int> > > &adj_list){

}

int main(void){

    int vertices, edges;
    cin>>vertices>>edges;

    vector< vector< pair<int, int> > > adj_list(vertices, vector<pair<int, int>>());

    // graph input as adjacency list
    for(int i=0; i<edges; ++i){
        int u, v, w;
        cin>>u>>v>>w;

        adj_list[u].push_back({w,v});
        adj_list[v].push_back({w,u});
    }

    int start;
    cin>>start;

    pq.push({0, start});

    mst_prim(adj_list);             // Function call for prim's algo 

    return 0;       
}
