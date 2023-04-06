#include <bits/stdc++.h>
using namespace std; 

int table[100][100];

int ed(string st1, int len1, string st2, int len2){
    if(len1 == 0)
        return len2;
    else if(len2 == 0)
        return len1;
    else if(st1[len1-1] == st2[len2-1])
        return ed(st1, len1-1, st2, len2-1);
    else
        return min(ed(st1, len1-1, st2, len2-1), min(ed(st1, len1, st2, len2-1), ed(st1, len1-1, st2, len2)));
}

int main(void){
    string st1, st2;
    cin>>st1>>st2;

    int len1 = st1.length(), len2 = st2.length();

    cout<<"Edit distance: "<<ed(st1, len1, st2, len2)<<endl;

    return 0;
}