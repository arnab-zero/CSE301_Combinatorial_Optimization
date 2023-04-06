#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

vector<int> dis(100, INT_MAX);

int dijkstra(vector<vector<pair<int,int> > > &v, int source, int dest){

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>>> pq;
    pq.push({0,source});
    dis[source] = 0;

    while(!pq.empty()){
        pair<int,int> u = pq.top();
        pq.pop();

        for(auto p: v[u.second]){
            if(dis[p.second]==INT_MAX){
                dis[p.second] = p.first;
                pq.push({dis[p.second],p.second});
            }
            else if(dis[p.second] > max(dis[p.second],p.first)){
                dis[p.second] = max(dis[p.second],p.first);
                pq.push({dis[p.second], p.second});
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
            v[a].pb({w,b});
            v[b].pb({w,a});
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
