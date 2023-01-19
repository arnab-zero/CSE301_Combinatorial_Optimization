#include <bits/stdc++.h>                // Still has issues; needs to be fixed.
using namespace std;

#define optimal_price_array_size 10000

int cut_rod(int length, int price, int optimal_price[]) {
    int maxPrice = price;    // for each length, corresponding index.

    for(int i=1; i<=length/2; ++i){
         maxPrice = max(maxPrice, optimal_price[i] + optimal_price[length-i]);
    }

    return maxPrice;
}

int main(void){
    int n, length;
    cout<<"Enter number of lengths: ";
    cin>>n;
    int price[n+1];

    cout<<"Enter lengths and corresponding price: ";
    for(int i=0; i<n; ++i){
        cin>>length;
        cin>>price[length];
    }

    int optimal_price[optimal_price_array_size];
    for(int i=0; i<optimal_price_array_size; ++i){
        optimal_price[i] = -1;
    }
    
    optimal_price[1] = price[1];

    for(int i=2; i<n+1; ++i){       // Time complexity: O(n*n)
        optimal_price[i] = cut_rod(i, price[i], optimal_price);
    }
    cout<<endl<<"Maximum price for each length: ";
    for(int i=1; i<n+1; ++i){
        cout<<i<<" "<<optimal_price[i]<<endl;
    }

    int test;
    cout<<"Enter query number: ";
    cin>>test;

    while(test--){
        int length;

        cout<<"Enter length to find max price: ";
        cin>>length;
        
        //if(optimal_price[length] == -1){
            optimal_price[length] = cut_rod(length, 0, optimal_price);
            cout<<"Max price: "<<optimal_price[length]<<endl;
        //}
        //else 
        //    cout<<"Max price: "<<optimal_price[length]<<endl;
    }

    return 0;


}