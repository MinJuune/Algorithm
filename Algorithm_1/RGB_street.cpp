// 백준 RGB 거리

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    int arr[1001][3];
    int dp[3];
    int temp[3];

    int R,G,B;

    for(int i=0;i<N;i++){
        cin>>R>>G>>B;
        arr[i][0]=R;
        arr[i][1]=G;
        arr[i][2]=B;
    }

    for(int i=0;i<N;i++){
        if(i==0){
            temp[0]=arr[i][0];
            temp[1]=arr[i][1];
            temp[2]=arr[i][2];
        }
        else{
            temp[0]=min(arr[i][0]+dp[1], arr[i][0]+dp[2]);
            temp[1]=min(arr[i][1]+dp[0], arr[i][1]+dp[2]);
            temp[2]=min(arr[i][2]+dp[0], arr[i][2]+dp[1]);
        }

        for(int j=0;j<3;j++){
            dp[j]=temp[j];
        }
    }

    int min=dp[0];
    for(int i=0;i<3;i++){
        if(min>dp[i]){
            min=dp[i];
        }
    }
    cout<<min;

}