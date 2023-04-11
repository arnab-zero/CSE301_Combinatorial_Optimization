#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

int paths_table[100][100];

int uniquePaths(int m, int n){

    if(paths_table[m][n]!=0)
        return paths_table[m][n];

    if(paths_table[m-1][n]!=0 and paths_table[m][n-1]!=0)
        return paths_table[m][n] = paths_table[m-1][n] + paths_table[m][n-1];
    
    return uniquePaths(m,n-1) + uniquePaths(m-1, n);  
}

int main(void){

    int m, n;
    cin>>m>>n;

    --m, --n;       //*****

    for(int i=0; i<m+1; ++i)
        paths_table[i][0] = 1;
    
    for(int i=0; i<n+1; ++i)
        paths_table[0][i] = 1;

    cout<<"Number of unique paths in the grid: "<<uniquePaths(m, n)<<endl;
    
    return 0;
}
