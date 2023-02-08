#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

vector<lli> v(1000, -1);

lli getFibonacci(lli n){
    if(n <= 1)
        return n;
    else if(v[n] != -1)
        return v[n];

    v[n] = getFibonacci(n-1) + getFibonacci(n-2);

    return v[n];
}

int main(void){
    lli testCount, input;
    cin>>testCount;

    while(testCount--){
        cin>>input;
        cout<<getFibonacci(input)<<endl;
    }

    return 0;
}