// 백준 쉬운 계단 수

#include <iostream>
using namespace std;

long long dp[101][9];

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        for(int j=1;j<=9;j++){
            if(i==0){
                dp[i][j]=1;
            }
            else if(i==1){
                if(j==9){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=2;
                }
            }
            else{
                if(j==1){
                    dp[i][j]=(dp[i-2][j]+dp[i-1][j+1]) %1000000000;
                }
                else if(j==9){
                    dp[i][j]=dp[i-1][j-1] %1000000000;
                }
                else{
                    dp[i][j]=(dp[i-1][j-1]+dp[i-1][j+1]) %1000000000;
                }
            }
        }
    }

    int sum=0;
    for(int i=1;i<=9;i++){
        sum+=dp[N-1][i];
        sum%=1000000000;
    }
    cout<<sum;
}

// 왜 % 부분은 계산할때마다 해줘야되는거지?