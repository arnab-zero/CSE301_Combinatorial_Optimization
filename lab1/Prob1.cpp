#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

// Global 2d vector for storing the adjacency matrix
vector<vi> v(100, vi (100, INT_MAX));

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

// main function
int main(void){

    int vertices;       // number of total vertices;
    cin>>vertices;

    int edges;      // number of input edges;
    cin>>edges;

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
    cout<<"APSP: "<<endl;
    for(int i=1; i<vertices+1; ++i){
        for(int j=1; j<vertices+1; ++j){
            cout<<v[i][j]<<spc;
        }
        cout<<endl;
    }
    
    return 0;
}
