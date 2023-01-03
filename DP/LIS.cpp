/*
Code: Longest increasing subsequence using dp;
Time complexity: O(n*n);
01:21, jan 2nd, 2023;
*/

#include <bits/stdc++.h>
using namespace std;

#define spc " "
#define tab "\t"


int main(void){
    int n;
    cout<<"Enter number of inputs: ";
    cin>>n;

    int input[n], prev[n], length[n];
    int maxLengthIndex = 0, maxLength = 0;

    for(int i=0; i<n; ++i){
        cin>>input[i];
        prev[i] = -1;
        length[i] = 1; 
    }

    // for(int i=0; i<n; ++i){
    //     cout<<i+1<<tab<<input[i]<<tab<<prev[i]<<tab<<length[i]<<endl;
    // }

    for(int i=0; i<n; ++i){
        int tempLength = 0, tempIndex = -1;

        for(int j=0; j<i; ++j)
        {
            if(tempLength < length[j] && input[j] < input[i])
                tempIndex = j;
            else if(tempLength == length[j] && input[j] < input[i] && input[j]<input[tempIndex])
                tempIndex = j; 
        }

        if(tempIndex != -1){
            prev[i] = tempIndex;
            length[i] = length[tempIndex] + 1;
        }

        if(length[i] > maxLength){
            maxLength = length[i];
            maxLengthIndex = i;
        }
    }

    //cout<<maxLengthIndex<<spc<<maxLength<<endl;
    int lis[maxLength];
    int j = maxLengthIndex;

    for(int i = maxLength-1; i>=0; --i){
        lis[i] = input[j];
        j = prev[j];
    }

    cout<<"LIS length: "<<maxLength<<endl;
    cout<<"LIS: ";
    for(int i=0; i<maxLength; ++i)
        cout<<lis[i]<<spc;
    cout<<endl;

    return 0;
}
