#include <bits/stdc++.h>
using namespace std;

int main(void){
    string str1, str2;
    cin>> str1 >> str2;

    int len1 = str1.length() + 1, len2 = str2.length() + 1, n = len1 * len2;
    int array[len1][len2];
    char marker[len1][len2];
    int len = max(len1, len2);

    for(int j=0; j<len; ++j){          // 0 0 0 0 
        array[0][j] = 0;               // 0 * * *
        array[j][0] = 0;               // 0 * * *
    }                          // for i = 3 & j = 4;

    int i=1, j=1;

    for(int k=0; k<n; ++k){

        if(i == 1 && j == 1){
            (str1[0] == str2[0])?(array[1][1] = 1):(array[1][1] = 0);
        }

        if(array[i][j-1] != array[i-1][j])
        {
            if(array[i][j-1] > array[i-1][j]){
                array[i][j] = array[i][j-1];
                marker[i][j] = 'H';
            }
            else{
                array[i][j] = array[i-1][j];
                marker[i][j] = 'V';
            }

        }
        else{
            if(str1[i-1] == str2[j-1])
            {
                array[i][j] = array[i-1][j-1] + 1;
                marker[i][j] = 'C';
            }
            else{
                array[i][j] = array [i][j-1];
                marker[i][j] = 'H';
            } 
            
        }
        
        ++j;

        if(j == len2){
            j=1;
            ++i;
        }

        if(i == len1)
            break;
    }

    i = len1-1, j = len2-1;
    stack<char> lcs;
    
    while(i>0 && j>0){
        if(marker[i][j] == 'H')
            --j;
        else if(marker[i][j] == 'V')
            --i;
        else if(marker[i][j] == 'C'){
            lcs.push(str1[i-1]);
            --i, --j;
        }
    }

    // for(int i=0; i<len1; ++i){
    //     for(int j=0; j<len2; ++j){
    //         cout<<array[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<"LCS length: "<<array[len1-1][len2-1]<<endl;

    cout<<"LCS: ";
    while(!lcs.empty()){
        char x = lcs.top();
        cout<<x;
        lcs.pop();
    }
    cout<<endl;

    return 0;
}



/*

string1: abcab  => abc      ab
string2: cba    =>   c  b   a               LCS => ca

Sample visualization:
    (a,c) => 0                  (a, cb) => 0                     (a,cba) => 1
   (ab,c) => 0                  (ab,cb) => 1                    (ab,cba) => 1
  (abc,c) => 1                (abc, cb) => 1                   (abc,cba) => 1
 (abca,c) => 1                (abca,cb) => 1                  (abca,cba) => 2
(abcab,c) => 1               (abcab,cb) => 2                 (abcab,cba) => 2

LCS length: 2

*/

