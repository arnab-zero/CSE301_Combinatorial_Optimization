#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

bool coin_change(int coins[], int n, int sum){
    if(sum == 0)
        return true;
    if(sum < 0)
        return false;
    if(n <= 0)
        return 0;

    return coin_change(coins, n-1, sum) or coin_change(coins, n, sum-coins[n-1]);
}

int main(void){

    int n, sum;
    cin>>n>>sum;

    int coins[n];
    for(int i=0; i<n; ++i)
        cin>>coins[i];

    cout<<"Coin change ";

    if(coin_change(coins, n, sum))
        cout<<"possible."<<endl;
    else 
        cout<<"not possible."<<endl;

    return 0;
}
