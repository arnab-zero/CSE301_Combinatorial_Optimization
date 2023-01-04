/*

Code: Determining maximum sum interval in a sequence of integers.
Time complexity: O(n)
written at 12:22, january 5, 2023

*/

#include <bits/stdc++.h>
using namespace std;

#define spc " "

int main(void){
    int count;
    cin>>count;

    int input[count];
    for(int i=0; i<count; ++i)
        cin>>input[i];
    
    int result[100][3];

    // for(int i=0; i<100; ++i)
    // {
    //     if(i<count)
    //         cout<<input[i]<<endl;
    //     cout<<result[i][0]<<spc<<result[i][1]<<spc<<result[i][2]<<endl;
    // }

    int sum = 0, index = 0;
    int i = 0, j = 0;

    while(i < count){
        sum += input[j];

        result[index][0] = i;
        result[index][1] = j;
        result[index][2] = sum;

        ++index;
        ++j;

        if(j == count){
            ++i;
            j = i;
            sum = 0;
        }
    }

    int maximum = result[0][2], max_index = 0;

    for(i = 1; i<index; ++i){
        if(result[i][2] > maximum){
            maximum = result[i][2];
            max_index = i;
        }
    }

    cout<<"Maximum sum: "<<result[max_index][2]<<endl;
    cout<<"Max sum interval: "<<result[max_index][0]+1<<spc<<result[max_index][1]+1<<endl;
    
    cout<<"Consecutive subsequence: ";
    for(i = result[max_index][0]; i <= result[max_index][1]; ++i){
        cout<<input[i]<<spc;
    }
    cout<<endl;
    
    return 0;
}