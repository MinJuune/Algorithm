#include <iostream>
using namespace std;

int bin(int n, int k){
    if(k==0 || k==n){
        return 1;
    }
    else{
        return bin(n-1,k-1)+bin(n-1,k);
    }
}

int main(){
    int n,k;
    cin>>n>>k;

    cout<<bin(n,k);
}