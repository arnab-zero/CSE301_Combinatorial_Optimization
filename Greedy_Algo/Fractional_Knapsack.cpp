#include<bits/stdc++.h>
using namespace std;

struct Items{
    int index;
    int weight;
    int price;
    float value;

    Items(int index, int weight, int price, float value): index(index), weight(weight), price(price), value(value)
    {}

};

struct compareValue{
    bool operator()(Items const& item1, Items const& item2){
        return item1.value < item2.value;
    }
};

int main(void){
    int itemCount;
    cout<<"Enter number of items: ";
    cin>>itemCount;

    int itemIndex[itemCount], itemWeight[itemCount], itemPrice[itemCount];
    float itemValue[itemCount];

    cout<<"Enter item weight & price(space separated): ";
    for(int i=0; i<itemCount; ++i){
        itemIndex[i] = i+1;
        cin>>itemWeight[i]>>itemPrice[i];
        itemValue[i] = itemPrice[i]/itemWeight[i];
    }

    priority_queue<Items, vector<Items>, compareValue> itemsPQ;

    for(int i=0; i<itemCount; ++i){
        itemsPQ.push(Items(itemIndex[i], itemWeight[i], itemPrice[i], itemValue[i]));
    }

    /*while(!itemsPQ.empty()){
        Items it = itemsPQ.top();
        itemsPQ.pop();
        cout<<it.price<<" "<<it.weight<<" "<<it.value<<" "<<endl;
    }*/

    int capacity, totalValue = 0;
    cout<<"Enter knapsack capacity: ";
    cin>>capacity;

    cout<<"\nCollected items: "<<endl;
    while(!itemsPQ.empty() && capacity){
        Items it = itemsPQ.top();
        itemsPQ.pop();
        
        if(capacity >= it.weight){
            capacity -= it.weight;
            cout<<"Item "<<it.index<<": "<<it.weight<<" unit weight."<<endl; 
            totalValue += it.price;
        }
        else {
            cout<<"Item "<<it.index<<": "<<capacity<<" unit.weight."<<endl;
            totalValue += it.value*capacity;
            capacity = 0;
        }
    }

    cout<<"\nTotal value collected: "<<totalValue<<endl;

    return 0;
}