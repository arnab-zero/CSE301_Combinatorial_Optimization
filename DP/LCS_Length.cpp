#include <bits/stdc++.h>
using namespace std;

int main(void){
    string str1, str2;
    cin>> str1 >> str2;

    int len1 = str1.length() + 1, len2 = str2.length() + 1, n = len1 * len2;
    int array[len1][len2];
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
            array[i][j] = max(array[i][j-1], array[i-1][j]);
        else{
            if(str1[i-1] == str2[j-1])
                array[i][j] = array[i-1][j] + 1;
            else 
                array[i][j] = array [i-1][j];
        }
        
        ++j;

        if(j == len2){
            j=1;
            ++i;
        }

        if(i == len1)
            break;
    }

    // for(int i=0; i<len1; ++i){
    //     for(int j=0; j<len2; ++j){
    //         cout<<array[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<"LCS length: "<<array[len1-1][len2-1]<<endl;
    return 0;
}



/*

string1: abcab  => abc      ab
string2: cba    =>   c  b   a

Sample visualization:
    (a,c) => 0                  (a, cb) => 0                     (a,cba) => 1
   (ab,c) => 0                  (ab,cb) => 1                    (ab,cba) => 1
  (abc,c) => 1                (abc, cb) => 1                   (abc,cba) => 1
 (abca,c) => 1                (abca,cb) => 1                  (abca,cba) => 2
(abcab,c) => 1               (abcab,cb) => 2                 (abcab,cba) => 2

LCS length: 2

*/

