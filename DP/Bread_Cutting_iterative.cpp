#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

#define Length 101
vi cuts(Length);
vector<vi> table(Length, vi(Length, -1));

int main(void){

    int length, n, m;
    cin>>length>>m;

    n=m+2;
    cuts[0] = 0;
    for(int i=1; i<m+1; ++i)
        cin>>cuts[i];
    
    for(int i=1; i<m+1; ++i){
        for(int j=1; j<m+1; ++i){
            
        }
    }



}
