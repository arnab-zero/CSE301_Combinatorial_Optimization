#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define pii pair<int, int>
#define spc " "
#define tab "\t"
typedef long long int lli;

priority_queue<pii, vector<pii>, greater<pii>> pq;
vector<bool> vis(20, false);       // marks if a vertex is already visited or not
vector<int> weight(20, INT_MAX);
vector<int> parent(20, -1);

void mst_prim(vector< vector<pair<int, int> > > &adj_list){

    while(!pq.empty()){
        pair<int, int> current = pq.top();
        pq.pop();

        if(vis[current.second])
            continue;
        
        vis[current.second] = true;

        for(auto i: adj_list[current.second]){
            if(weight[i.second] > i.first and !vis[i.second]){
                weight
[i.second] = i.first;
                parent[i.second] = current.second;
                pq.push({i.first, i.second}); 
            }
        }
    }
}

int main(void){

    freopen("Prim_Algo_input.txt", "r", stdin);
    freopen("Prim_Algo_output.txt", "w", stdout);

    int vertices, edges;
    cin>>vertices>>edges;

    vector< vector< pair<int, int> > > adj_list(vertices+1);

    // graph input as adjacency list
    for(int i=0; i<edges; ++i){
        int u, v, w;
        cin>>u>>v>>w;

        adj_list[u].push_back({w,v});
        adj_list[v].push_back({w,u});
    }

    cout<<"Considering vertex 1 as the root vertex."<<endl<<endl;
    pq.push({0, 1});

    // cout<<pq.top().second<<endl;
    // for(auto i: adj_list[pq.top().second]){
    //     cout<<i.second<<spc<<i.first<<endl;
    // }
    // for(int i=1; i<vertices+1; ++i){
    //     cout<<"vertex: "<<i<<endl;
    //     for(auto p:adj_list[i]){
    //         cout<<p.second<<spc<<p.first<<endl;
    //     }
    //     cout<<endl;
    // }

     mst_prim(adj_list);             // Function call for prim's algo 

    for(int i=1; i<vertices+1; ++i){
        cout<<"vertex "<<(char)(i+'a'-1)<<": ";
        cout<<" vis: "<<vis[i]<<tab;
        cout<<" weight: "<<weight[i]<<tab;
        cout<<" parent: "<<(char)(parent[i]+'a'-1)<<endl;
    }

    return 0;       
}
