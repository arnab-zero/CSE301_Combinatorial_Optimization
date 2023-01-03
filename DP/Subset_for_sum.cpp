#include <bits/stdc++.h>
using namespace std; 

#define vi vector<int>
#define pb push_back
#define pob pop_back
#define spc " "


int main(void){
    int n, targetSum, sum = 0, i=0;
    cout<<"Enter number of inputs: ";
    cin>>n;

    cout<<"Enter inputs: ";
    int input[n];
    for(int i=0; i<n; ++i)
        cin>>input[i];

    cout<<"Target sum: ";
    cin>>targetSum;

    vi v;   

    while(1){
        v.pb(i);
        sum += input[i];
        ++i;

        if(sum == targetSum){
            cout<<"Subset: ";
            for(int i=0; i<v.size(); ++i)
                cout<<input[v[i]]<<spc;
            cout<<endl;
        }
        else if(sum > targetSum)
        {
            sum -= input[v[v.size()-1]];
            v.pob();
        }

        if(v.size() == 1 && i == n)
            break;

        if(i == n)
        {
            sum -= input[v[v.size() - 1]];
            v.pob();
            i = v[v.size() - 1] + 1;        // change
            sum -= input[v[v.size() - 1]];
            v.pob();
        }
    }

    return 0;

}

/*

6
2 5 8 12 6 14

4
10 2 1 2

*/
