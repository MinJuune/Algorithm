// 백준 계단 오르기

#include <iostream>
#include <algorithm>
using namespace std;

int arr[301];
int dp[301];

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];

        if(i==0){
            dp[i]=arr[i];
        }
        else if(i==1){
            dp[i]=dp[0]+arr[i];
        }
        else if(i==2){
            dp[i]=max(dp[0]+arr[i], arr[i-1]+arr[i]);
        }
        else{
            dp[i]=max(dp[i-2]+arr[i], dp[i-3]+arr[i-1]+arr[i]);
        }
    }

    cout<<dp[n-1];
}

/*  
    쭉 나열하다 보면 
    작은 단위에서의 답이 큰 단위에서의 답으로 쓰일때가 있음
    패턴을 찾아내기
*/ 