/*

Code: Determining maximum sum interval in a sequence of integers.
Time complexity: O(n)
written at 12:22, january 5, 2023

*/

#include <bits/stdc++.h>
using namespace std;

#define vvi vector<vector<int>>
#define pb push_back
#define pob pop_back
#define spc " "

int main(void){
    int inputCount, i = 0, j = i;
    cin>>inputCount;

    int input[inputCount];
    for(i=0; i<inputCount; ++i)
        cin>>input[i];

    // for(int i=0; i<inputCount; ++i)
    //     cout<<input[i]<<spc;

    int result[100][3];     // stores starting and ending point of a
                            // subsequence and the in_between sum
    int sum = 0, result_array_index = 0;
    i = 0;

    while(1){

        sum += input[j];

        result[result_array_index][0] = i;
        result[result_array_index][1] = j;
        result[result_array_index][2] = sum;

        ++result_array_index;
        ++j;

        if(j == inputCount){
            j = ++i;
            sum = 0;
        }

        if(i == inputCount)
            break;
    }

    int maximum = result[0][2], max_index = 0;

    for(int i=1; i<result_array_index; ++i){
        if(result[i][2] > maximum){
            maximum = result[i][2];
            max_index = i;
        }
    }

    cout<<"Max sum: "<<result[max_index][2]<<endl;
    cout<<"Max sum interval: "<<result[max_index][0]+1<<spc<<result[max_index][1]+1<<endl;

    cout<<"Consecutive subsequence: ";
    for(int i = result[max_index][0]; i<=result[max_index][1]; ++i)
    {
        cout<<input[i]<<spc;
    }
    cout<<endl;

    return 0;
}

