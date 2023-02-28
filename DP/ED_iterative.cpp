#include <bits/stdc++.h>
using namespace std;

int main(void){
    string st1, st2;
    cin>>st1>>st2;

    int table[st1.length()][st2.length()];
    int i=0, j=0;

    while(i<=st1.length()){
        if(i == 0)
            table[i][j] = j;
        else if(j == 0)
            table[i][j] = i;
        else if(st1[i-1] == st2[j-1]){
            table[i][j] = table[i-1][j-1];
        }
        else 
            table[i][j] = min(table[i-1][j-1], min(table[i-1][j], table[i][j-1])) + 1;
    
        ++j;

        if(j > st2.length()){
            ++i, j = 0;
        }
    }

    cout<<table[st1.length()-1][st2.length()-1]<<endl;
    return 0;
}
