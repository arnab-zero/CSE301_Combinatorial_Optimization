#include <bits/stdc++.h>
using namespace std; 

#define vi vector<int>
#define pb push_back
#define pob pop_back
#define spc " "


bool existSubset(int a[], int n, int sum){

    if(sum == 0)
        return true;
    
    if(n == 0)
        return false;

    if(a[n-1] > sum)
        return existSubset(a, n-1, sum);
    
    return existSubset(a, n-1, sum) or existSubset(a, n-1, sum-a[n-1]);
}


int main(void){
    int n, sum;
    cin>>n>>sum;     // n = number of elements in sequence
                     // sum = target sum

    int a[n];
    for(int i=0; i<n; ++i)
        cin>>a[i];

    existSubset(a, n, sum)?(cout<<"Found."<<endl):(cout<<"Not found."<<endl);
    
    return 0;
}

/*

6
2 5 8 12 6 14

4
10 2 1 2

*/
