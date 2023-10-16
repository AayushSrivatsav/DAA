#include <bits/stdc++.h>
using namespace std;
struct Job{
    int id;
    int dead;
    int penalty;
};

class Solution{
public:
    bool static comparison(Job a,Job b){
        return a.penalty >b.penalty ;
    }
    pair <int,int> JobScheduling(Job arr[], int n){
        sort(arr,arr+n,comparison);

        int maxi=arr[0].dead;
        for(int i=1;i<n;i++){
            maxi = max(maxi,arr[i].dead);
        }
        int slot[maxi+1];
        for(int i=0;i<=maxi;i++){
            slot[i]=-1;
        }
        int penaltySum=0;
        for(int i=0;i<n;i++){
            penaltySum+=arr[i].penalty;
        }
        int countJobs=0,profitJobs=0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                if(slot[j]==-1){
                    slot[j]=i;
                    countJobs++;
                    penaltySum-=arr[i].penalty;
                    break;
                }
            }
        }
        return make_pair(countJobs,penaltySum);
    }
};
int main(){
    int n=7;
    Job arr[n] = {{1,14,80},{2,12,70},{3,14,60},{4,13,50},{5,11,40},{6,14,30},{7,16,20}};
    Solution ob;
    pair <int, int> ans = ob.JobScheduling(arr,n);
    cout<<ans.first<<"     "<<ans.second;

}

