#include<iostream>

using namespace std;

int stairs(int n)
{

    if(n==1||n==0){
        return 1;
    }
    else{

        return stairs(n-1)+stairs(n-2);
    }
}


int main()
{

    int n=5;
    int y=stairs(n);
    cout<<y;

}
