#include <iostream>
#include <algorithm>
using namespace std;

int bin2(int n, int k){
    int i,j;
    int DP[100][100];

    for(i=0;i<=n;i++){
        for(j=0;j<=min(i,k);j++){
            if(j==0 || j==i){
                DP[i][j]=1;
            }
            else{
                DP[i][j]=DP[i-1][j-1]+DP[i-1][j];
            }
        }
    }

    return DP[n][k];
}

int main(){
    int n,k;
    cin>>n>>k;

    cout<<bin2(n,k);
}