#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

vector<int> dis(100, INT_MAX);

int dijkstra(vector<vector<pair<int,int> > > &v, int source, int dest){

    priority_queue<int> pq;
    pq.push(source);
    dis[source] = 0;

    while(!pq.empty()){
        int u = pq.top();
        pq.pop();

        for(auto p: v[u]){
            if(dis[p.first]==INT_MAX){
                dis[p.first] = p.second;
                pq.push(p.first);
            }
            else if(dis[p.first] > max(dis[u],p.second)){
                dis[p.first] = max(dis[u],p.second);
                pq.push(p.first);
            }
        }
    }

    return dis[dest];
}

int main(void){

    for(int z=1; ; ++z){
        int vertices, edges, query;
        cin>>vertices>>edges>>query;

        if(vertices==0 and edges==0 and query==0)
            break;

        vector<vector<pair<int,int> > > v(vertices+1);

        for(int i=0; i<edges; ++i){
            int a, b, w;
            cin>>a>>b>>w;
            v[a].pb({b,w});
            v[b].pb({a,w});
        }

        cout<<"Case #"<<z<<endl;
        while(query--){
            int source, dest;
            cin>>source>>dest;
            cout<<dijkstra(v, source, dest)<<endl;
        }
    }

    return 0;
}
