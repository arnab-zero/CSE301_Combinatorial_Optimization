#include <bits/stdc++.h>
using namespace std;

#define Length 101              // Keep it greater than the input length
#define vi vector<int>
vi cuts(Length);
vector<vi> table(Length, vi(Length, -1));      // Stores minimum cost for certain cut

int min_cost(int start, int finish){
    int mini = INT_MAX;

    if(start>finish)
        return 0;

    if(table[start][finish] != -1)
        return table[start][finish];
    
    for(int i=start; i<finish+1; ++i){
        int cost = cuts[finish+1] - cuts[start-1] + min_cost(start, i-1) + min_cost(i+1, finish);
        if(cost < mini)
            mini = cost;
    }

    table[start][finish] = mini;        // Memoization
    return mini;              // Returns the minimum cost.
}

int main(void){
    int length, n, m;
    cin>>length>>m;

    n = m+2;
    cuts[0] = 0;
    for(int i=1; i<m+1; ++i){
        cin>>cuts[i];
    }
    cuts[n-1] = length;

    int minimum_cost = min_cost(1, m);

    cout<<minimum_cost<<endl;

}