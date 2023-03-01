#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

int maxCost(vi &cost, int n, vi &dp){
    if(n==0)
        return 0;
    if(dp[n]!=-1)
        return dp[n];

    int optimalCost = INT_MIN;
    for(int i=1; i<n+1; ++i){
        int temp = cost[i] + maxCost(cost, n-i, dp);
        (optimalCost>temp)?(optimalCost=optimalCost):(optimalCost=temp);
    }

    return optimalCost;
}

int main(void){

    int n;
    cin>>n;

    vi cost(n+1, 0);

    for(int i=1; i<n+1; ++i)
        cin>>cost[i];

    vi dp(n+2, -1);

    cout<<maxCost(cost, n, dp)<<endl;
    
    return 0;
}
