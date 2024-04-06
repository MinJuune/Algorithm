#include <iostream>
using namespace std;

int fibo2(int n){
    int i;
    int DP[1001];

    DP[0]=0;
    if(n>0){
        DP[1]=1;
        for(i=2;i<=n;i++){
            DP[i]=DP[i-1]+DP[i-2];
        }
    }

    return DP[n];
}

int main(){
    int n;
    cin>>n;

    cout<<fibo2(n);
}