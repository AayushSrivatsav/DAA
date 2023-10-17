#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};
class Solution{
public:
    bool static comparison(Item a, Item b){
        double r1 = (double)(a.value)/(double)(a.weight);
        double r2 = (double)(b.value)/(double)(b.weight);
        return r1>r2;
    }
    double fractionalKnapsack(int W, Item arr[],int n){
        sort(arr,arr+n,comparison);
        int curr=0;
        double finalans=0.0;
        for(int i=0;i<n;i++){
            if(arr[i].weight+curr<=W){
                finalans+=arr[i].value;
                curr+=arr[i].weight;
            }
            else{
                int rem = W-curr;
                finalans+=(arr[i].value/(double)arr[i].weight)*(double)rem;
                break;
            }
        }
        return finalans;
    }
};
int main(){
    int W=50;
    int n=3;
    Item arr[n] = {{60,10},{100,20},{120,30}};
    Solution ob;
    double ans = ob.fractionalKnapsack(W,arr,n);
    cout<<endl<<"The maximum value of knapsack: "<<ans;


}
