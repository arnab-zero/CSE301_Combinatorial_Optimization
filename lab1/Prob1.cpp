#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

// Global 2d vector for storing the adjacency matrix
vector<vi> v(100, vi (100, INT_MAX));
int query;  // number of query in each test case

void v_init(){
    for(int i=0; i<100; ++i){
        for(int j=0; j<100; ++j){
            v[i][j] = INT_MAX;
        }
    }
}

// Function for implementing the Floyd-Warshall Algorithm
void floyd_warshall(int n){

    for(int k=1; k<n; ++k){

        for(int i=1; i<n; ++i){

            for(int j=1; j<n; ++j){

                if(v[i][k]==INT_MAX or v[k][j]==INT_MAX)
                    continue;

                v[i][j] = min(v[i][j], max(v[i][k], v[k][j]));
            }

        }

    }
    
}


// driver function
void solve(){

    int vertices;       // number of total vertices;
    int edges;      // number of input edges;

    cin>>vertices>>edges>>query;

    if(vertices==0 and edges==0 and query==0)
        exit(1);

    v_init();   // initialize the v vector cells with INT_MAX

    // for undirected graph
    // input passed as adjacency list
    // deriving an adjacency matrix out of the input list
    for(int i=0; i<edges; ++i){
        int a, b, w;
        cin>>a>>b>>w;
        v[a][b] = w;
        v[b][a] = w;
    }

    for(int i=1; i<vertices+1; ++i){
        v[i][i] = 0;
    }

    // for(int i=1; i<vertices+1; ++i){
    //     for(int j=1; j<vertices+1; ++j){
    //         cout<<v[i][j]<<spc;
    //     }
    //     cout<<endl;
    // }

    // Floyd-Warshall function call
    floyd_warshall(vertices+1);

    // printing the APSP adjacency matrix
    // cout<<"APSP: "<<endl;
    // for(int i=1; i<vertices+1; ++i){
    //     for(int j=1; j<vertices+1; ++j){
    //         cout<<v[i][j]<<spc;
    //     }
    //     cout<<endl;
    // }
}


// main function
int main(void){

    freopen("Prob1_input.txt", "r", stdin);
    freopen("Prob1_output.txt", "w", stdout);

    for(int i=1; ; ++i){
        solve();

        cout<<"Case #"<<i<<endl;
        while(query--){
            int m, n;
            cin>>m>>n;
            if(v[m][n] != INT_MAX){
                cout<<v[m][n]<<endl;
            }
            else 
                cout<<"no path"<<endl;
        }
    }


    
    return 0;
}
