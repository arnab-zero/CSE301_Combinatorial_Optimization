#include <bits/stdc++.h>
using namespace std;

int max_price[101][101];

int calc_max_price(int price, int m, int n){
    
    int max1 = price, max2 = price;

    for(int i=1; i<max(m,n); ++i){
        if(i<m)
            max1 = max(max1, max_price[m-i][n]+max_price[i][n]);
        if(i<n)
            max2 = max(max2, max_price[m][n-i]+max_price[m][i]);
    }

    return max(max1, max2);
}

int main(void){
    int m, n;
    cout<<"Enter dimensions: ";
    cin>>m>>n;

    int input_price[m+1][n+1];
    cout<<"Enter price: ";

    for(int i=1; i<m+1; ++i){
        for(int j=1; j<n+1; ++j){
            cin>>input_price[i][j];
        }
    }

    for(int i=0; i<101; ++i){
        for(int j=0; j<101; ++i){
            max_price[i][j] = -1;
        }
    }

    int j = 1;
    for(int i=1; i<m+1; ++i){
        if(max_price[i][j] == -1){
            int mp = calc_max_price(input_price[i][j], i, j);
            max_price[i][j] = mp;
            max_price[j][i] = mp;
        }
        ++j;
        if(j == n+1)
            ++i;
    }

    j = 1;
    for(int i=1; i<m+1; ++i){
        cout<<max_price[i][j]<<" ";
        ++j;
        if(j==n+1)
            ++i;
    }

    return 0;
}

/*

[1,1] => [1,1]
[1,2] == [2,1] => max([1,2], [1,1]+[1+1])
[1,3] == [3,1] => max([1,3], [1,1]+[1,2])
[1,4] == [4,1] => max([1,4], [1,1]+[1,3])
               => max([1,4], [1,2]+[1,2])
               => max([1,4], [1,3]+[1,1])

[2,2] => max([2,2], [1,2]+[1,2])
[2,3] => max([2,3], [2,1]+[2,2])
      => max([2,3], [2,2]+[2,1])
[2,4] => max([2,4], [2,1]+[2,3])    => max([2,4], [1,4]+[1,4])
      => max([2,4], [2,2]+[2,2])
      => max([2,4], [2,3]+[2,1])

[3,3] => max([3,3], [1,3]+[2,3])    => max([3,3], [3,1]+[3,2])
      => max([3,3], [2,3]+[1,3])    => max([3,3], [3,2]+[3,1])



[4,3] => max([4,3], [1,3]+[3,3])    => max([4,3], [4,1]+[4,2])
      => max([4,3], [2,3]+[2,3])    => max([4,3], [4,2]+[4,1])
      => max([4,3], [3,3]+[1,3])

[4,4] => max([4,4], [1,4]+[3,4])    => max([4,4], [4,1]+[4,3])
      => max([4,4], [2,4]+[2,4])    => max([4,4], [4,2]+[4,2])
      => max([4,4], [3,4]+[1,4])    => max([4,4], [4,3]+[4,1])

[m,n] => max([m,n], [m-1,n]+[1,n])  => max([m])
      => max([m,n], [m-2,n]+[2,n])
      => max([m,n], [m-3,n]+[3,n])
      ... ... ... ... ... ... ...
      => max([m,n], [m-i,n]+[i,n])  => max([m,n], [m,n-i],[m,i])

*/

/*

## code:
for(int i=1; i<max(m+1,n+1); ++i){
    if(i<m+1)
        max1 = max([m,n], [m-i,n]+[i,n]);
    if(i<n+1)
        max2 = max([m,n], [m,n-i]+[m,i]);
}
max_price[m,n] = max(max1,max2);


*/


/*

Input: 

4 10

1 5 8 9 10 17 17 20 24 30
5 6 18 22 31 35 37 39 40 45 
8 18 22 34 37 39 42 43 45 48 
9 22 34 40 44 47 48 50 52 53

*/

