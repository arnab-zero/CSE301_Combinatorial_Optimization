#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

bool check_cycle(){

}

void topological_sort(){

}

int main(void){

    int vertices, edges;
    cin>>vertices>>edges;

    vector<vector<int>> adj_mat(vertices, vector<int>(vertices, INT_MAX));

    for(int i=0; i<edges; ++i){
        int u, v, w;
        cin>>u>>v>>w;
        adj_mat[u][v] = w;
    }

    

}
