#include <bits/stdc++.h>
using namespace std;


bool comparison(const pair<int,int>&a, const pair<int,int>&b){
    return a.second<b.second;
}
vector <pair<int, int>> intervalScheduling(vector<pair<int, int>>& intervals){
    sort(intervals.begin(),intervals.end(),comparison);
    vector<pair<int, int>> selectedInt;
    selectedInt.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++){
        if(intervals[i].first >=selectedInt.back().second){
            selectedInt.push_back(intervals[i]);
        }
    }
    return selectedInt;

}
int main(){
    vector<pair<int ,int>> intervals={ {1,3},{2,4},{3,5},{4,6},{5,7}};
    vector <pair<int,int>> selectedIntervals = intervalScheduling(intervals);
    for (const pair<int, int>& interval : selectedIntervals) {
        cout << "[" << interval.first << ", " << interval.second << "] ";
    }
    cout << endl;
    int m=intervals.size();
    int n=selectedIntervals.size();
    cout<<m-n;
    return 0;

}
