#include <iostream>
using namespace std;
#include <algorithm>

bool isPrime(int num){
    for(int i=2;i<=num/2;i++){
        if(num%i==0){
            return false;
        }
        else{
            continue;
        }
    }
    return true;
}

void solve(int m, int n){
    for(int i=m;i<=n;i++){
        if(isPrime(i)){
            cout<<i<<'\n';
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M,N;
    cin>>M>>N;

    solve(M,N);

    return 0;

}