/*

sample input: 

abc
abbabc

*/


#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

lli calculate_hash(string st, int start_ind, int end_ind){

    int length = end_ind - start_ind + 1;
    lli hash = 0;

    for(int i=start_ind; i<end_ind+1; ++i){
        hash = 10*hash + st[i];
    }

    return hash;
}


int rabin_karp(string st1, string st2){

    int i = 0, j = st1.size()-1;

    lli hash1 = calculate_hash(st1, i, j);
    lli hash2 = calculate_hash(st2, i, j);

    //cout<<hash1<<spc<<hash2<<endl;

    while(true){
        if(hash1 == hash2)
            return i;

        if(j+1 == st2.size())
            return -1;
        
        hash2 = 10*(hash2 - ((int)st2[i++])*pow(10, st1.size()-1)) + st2[++j];
        // cout<<i<<spc<<j<<spc;
        // cout<<hash2<<endl;
    }

}


int main(void){

    string st1, st2;
    cin>>st1>>st2;

    cout<<rabin_karp(st1, st2)<<endl;

    return 0;
}
