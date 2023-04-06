#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

int main(void){

    priority_queue<pair<int,int>> pq;
    pq.push({3,4});
    pq.push({2,1});
    pq.push({5,2});
    pq.push({4,3});

    while(!pq.empty()){
        pair<int,int> p = pq.top();
        pq.pop();
        cout<<p.first<<spc<<p.second<<endl;
    }

    return 0;
}
