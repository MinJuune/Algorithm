// 백준 포도주 시식

#include <iostream>
#include <algorithm>
using namespace std;

int dp[2][10001];   
// dp[0][]에다가는 현재까지의 최댓값
// dp[1][]에다가는 현재꺼O + 전꺼X + 전전꺼까지의 최댓값 
int arr[10001];

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin>>n;

    int maxi=0;
    int temp=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];

        if(i==0){
            dp[0][i]=arr[i];
            dp[1][i]=arr[i];
        }
        else if(i==1){
            dp[0][i]=arr[i]+arr[i-1];
            dp[1][i]=arr[i];
        }
        else{
            temp= max(arr[i]+dp[1][i-1], arr[i]+dp[0][i-2]);
            dp[0][i]= max(temp, dp[0][i-1]);
            dp[1][i]=arr[i]+dp[0][i-2];
        }

        if(maxi<dp[0][i]){
            maxi=dp[0][i];
        }
    }

    cout<<maxi;

    
}