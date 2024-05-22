// 백준 01타일

#include <iostream>
using namespace std;

long long dp[1000001]={0};

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    dp[1]=1;
    dp[2]=2;
    if(N!=1 && N!=2){
        for(int i=3;i<N+1;i++){
            dp[i]=(dp[i-2]+dp[i-1])%15746;
        }
    }
    
    cout<<dp[N]%15746;
}

// 우선 쭉 나열해보고 반복되는 규칙 찾으면 dp로 풀기
// 작은 문제들의 답으로 큰 문제들을 풀수 있는가 판단