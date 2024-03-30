// 백준 정수 삼각형

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int arr[501][501];  // 입력받은 정수 삼각형
    int dp[501];        // 각 줄의 최댓값
    int temp[501];      // 최댓값 구하는 과정에서 이전 dp 값 필요함

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }
    //일단 입력 전부 받음

    for(int i=0;i<n;i++){
        if(i==0){
            dp[0]=arr[0][0];
        }
        else{
            for(int j=0;j<=i;j++){
                if(j==0){
                    temp[j]=dp[j]+arr[i][j];
                }
                else if(j==i){
                    temp[j]=dp[j-1]+arr[i][j];
                }
                else{
                    if(dp[j-1]+arr[i][j] < dp[j]+arr[i][j]){
                        temp[j]=dp[j]+arr[i][j];
                    }
                    else{
                        temp[j]=dp[j-1]+arr[i][j];
                    }
                }
            }
            for(int k=0;k<=i;k++){
               dp[k]=temp[k];
            }
        }
    }

    int max=dp[0];
    for(int i=0;i<n;i++){
        if(max<dp[i]){
            max=dp[i];
        }
    }
    cout<<max;
}
