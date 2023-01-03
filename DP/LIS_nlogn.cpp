/*
About: Longest increasing subsequence using dp; 
Time complexity: O(nlogn);

*/

#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define pb push_back
#define spc " "
#define tab "\t"


int main(void){
    int n;
    cout<<"Enter number of inputs: ";
    cin>>n;

    int input[n], inputCopy[n];     // inputCopy stores a copy of input array.

    for(int i=0; i<n; ++i)
    {
        cin>>input[i];
        inputCopy[i] = input[i];
    }

    sort(inputCopy, inputCopy+n);   // inputCopy array sorted.
    
    vi lis;                 // lis vector stores the longest increasing subsequence.

    for(int i=0; i<n; ++i){
        

    }


}


