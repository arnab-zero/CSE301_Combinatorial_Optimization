#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

// Function for implementing the Floyd-Warshall Algorithm
void floyd_warshall(vector<vi> &v, int n){

    for(int k=1; k<n; ++k){

        for(int i=1; i<n; ++i){

            for(int j=1; j<n; ++j){

                if(v[i][k]==INT_MAX or v[k][j]==INT_MAX)
                    continue;

                v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
            }

        }

    }
    
}

// main function
int main(void){

    freopen("prob2_input.txt", "r", stdin);
    freopen("prob2_output.txt", "w", stdout);

    for(int z=1; ; ++z){

        vector<pair<int,int> > adj_list;        // To store the inputs temporarily
        vector<int> list;

        int u, v;
        cin>>u>>v;

        if(u==0 and v==0)       // Ends programme
            break;

        adj_list.pb({u,v});
        list.pb(u);
        list.pb(v);

        while(1){
            cin>>u>>v;
            if(u==0 and v==0)
                break;
            adj_list.pb({u,v});
            list.pb(u);
            list.pb(v);
        }

        // actual vertex count and vertices
        int vertices = 1;      // number of vertices
        sort(list.begin(), list.end());
        map<int, int> mp;
        mp[list[0]] = vertices;
        for(int i=1; i<list.size(); ++i){
            if(list[i] != list[i-1]){
                mp[list[i]] = ++vertices;
            }
        } 


        // 2d vector for storing the adjacency matrix
        vector<vi> adj_mat(vertices+1, vi (vertices+1, INT_MAX));

        // Initializing the matrix
        for(auto i: adj_list){
            adj_mat[mp[i.first]][mp[i.second]] = 1;
        }

        for(int i=1; i<vertices+1; ++i){
            adj_mat[i][i] = 0;
        }

        floyd_warshall(adj_mat, vertices+1);

        int sum_of_clicks = 0;

        for(int i=1; i<vertices+1; ++i){
            for(int j=1; j<vertices+1; ++j){
                sum_of_clicks += adj_mat[i][j];
            }
        }

        // cout<<"mat: "<<endl;
        // for(int i=1; i<vertices+1; ++i){
        //     for(int j=1; j<vertices+1; ++j){
        //         cout<<adj_mat[i][j]<<spc;
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;

        // cout<<sum_of_clicks<<endl;
        // cout<<"res: "<<sum_of_clicks/(vertices*vertices-vertices)<<endl;
        // cout<<"vertices: "<<vertices<<endl;

        printf("Case %d: ", z);
        printf("average length between pages = %.3f clicks\n", (float)sum_of_clicks/(vertices*vertices-vertices));

    }

    return 0;

}
