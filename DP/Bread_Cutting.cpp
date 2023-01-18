#include <bits/stdc++.h>
using namespace std;

#define Length 101              // Keep it greater than the input length
int table[Length][Length];      // Stores minimum cost for certain cut

int min_cost(int start, int finish, int cuts[]){
    int mini = INT_MAX;

    // if(table[cuts[start]][cuts[finish]] != -1)
    //     return table[cuts[start]][cuts[finish]];
    
    for(int i=start+1; i<finish; ++i){
        int cost = cuts[finish] - cuts[start] + min_cost(start, i, cuts) + min_cost(i, finish, cuts);
        if(cost < mini)
            mini = cost;
    }

    table[cuts[start]][cuts[finish]] = mini;        // Memoization
    return mini;              // Returns the minimum cost.
}

int main(void){
    int length, n, m;
    cin>>length>>m;

    n = m+2;
    int cuts[n];        // Stores the points where the cuts should be done
    cuts[0] = 0;
    for(int i=1; i<m+1; ++i){
        cin>>cuts[i];
    }
    cuts[n-1] = length;

    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            table[i][j] = -1;
        }
    }

    for(int i=0; i<n; ++i){
        table[cuts[i]][cuts[i]] = 0;
        if(i==n-1)
            continue;
        table[cuts[i]][cuts[i+1]] = 0;
        table[cuts[i+1]][cuts[i]] = 0;
    }

    int minimum_cost = min_cost(0, n-1, cuts);

    cout<<minimum_cost<<endl;

}