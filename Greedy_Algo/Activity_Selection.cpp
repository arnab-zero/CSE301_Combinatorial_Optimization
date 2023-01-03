#include<bits/stdc++.h>
using namespace std;

int main(void){
    int activityCount;
    cout<<"Enter activity count: ";
    cin>>activityCount;

    int activityStart[activityCount], activityEnd[activityCount];
    vector<int> optSolution;

    cout<<"Enter start and end time of each activity: ";
    
    for(int i=0; i<activityCount; ++i){
        cin>>activityStart[i]>>activityEnd[i];
    }

    int last = activityEnd[0];
    optSolution.push_back(0);

    for(int i=1; i<activityCount; ++i){
        if(activityStart[i] >= last)
        {
            optSolution.push_back(i);
            last = activityEnd[i];
        }
    }

    for(auto i:optSolution){
        cout<<"Activity "<<i+1<<": "<<"Starting at "<<activityStart[i]<<" & ending at "<<activityEnd[i]<<endl;
    }
    
    return 0;

}