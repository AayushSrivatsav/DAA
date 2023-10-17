#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int toys(int arr[],int n)
{

    int index=0;
    int toy=0;




    while(index<n){
        toy=toy+1;

        int lb=arr[index];
        int ub=arr[index]+4;
        while(index<n and arr[index]<=ub){
            index++;

        }
    }
    cout<<toy;

}

int main()
{


    int w[]={1 ,2 ,3 ,10 ,17};
    int n=5;
    toys(w,n);
}
