// 백준 가장 긴 증가하는 부분 수열

#include <iostream>
#include <algorithm>
using namespace std;

int A[1001];
int dp[1001];

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        dp[i]=1;
    }
    

    for(int i=0;i<N;i++){
        cin>>A[i];
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<i;j++){
            if(A[i]>A[j]){
                dp[i]=max(dp[i], dp[j]+1);
            }
            else{
                continue;
            }
        }
    }

    int max=dp[0];
    for(int i=0;i<N;i++){
        if(max<dp[i]){
            max=dp[i];
        }
    }
    cout<<max;
}