#include<bits/stdc++.h>     //using dp
using namespace std;

int arr[100];
int top = 2;

void getFibonacciNumber(int num){
    while(num>top)
    {
        arr[top+1] = arr[top] + arr[top-1];
        ++top;
    }
}

int main(void){
    arr[1] = 0, arr[2] = 1;     //starting from index 1
    int testCount, input;
    cin>>testCount;

    while(testCount--){
        cin>>input;
        if(arr[input]==0 && input!=1)
            getFibonacciNumber(input);
        cout<<arr[input]<<endl;
    }

    return 0;
}
