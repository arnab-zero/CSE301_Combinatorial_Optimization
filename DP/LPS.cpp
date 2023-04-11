// C++ program of above approach
#include<bits/stdc++.h>
using namespace std;
 
// A utility function to get max of two integers
int max (int x, int y) 
{ 
    return (x > y)? x : y; 
}
 

int lps(char *seq, int i, int j)
    {
    // Base Case 1: If there is only 1 character
    if (i == j)
        return 1;
    
    // Base Case 2: If there are only 2
    // characters and both are same
    if (seq[i] == seq[j] && i + 1 == j)
        return 2;
    
    // If the first and last characters match
    if (seq[i] == seq[j])
        return lps (seq, i+1, j-1) + 2;

    return max( lps(seq, i, j-1), lps(seq, i+1, j) );
}
 

int main()
{
    char seq[] = "ABABBABC";
    int n = strlen(seq);
    cout << "The length of the LPS is "
         << lps(seq, 0, n-1);
    return 0;
}