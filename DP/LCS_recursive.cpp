#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"
typedef long long int lli;

int lcs(string a, string b, int m, int n){
    if(m==0 or n==0)
        return 0;
    else if(a[m-1]==b[n-1])
        return 1+lcs(a, b, m-1, n-1);
    else 
        return max(lcs(a, b, m, n-1), lcs(a, b, m-1, n));
}

int main(void){
    string sa, sb;
    cout<<"Enter input strings: ";
    cin>>sa>>sb;

    cout<<"LCS length: "<<lcs(sa, sb, sa.size(), sb.size());

    return 0;
}
