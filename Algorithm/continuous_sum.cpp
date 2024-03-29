// 백준 연속합

#include <iostream>
#include <vector>
using namespace std;

int dp[100001];

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin>>n;

    vector<int> vec;

    int num;
    int max;
    for(int i=0;i<n;i++){
        cin>>num;
        vec.push_back(num);
    }

    for(int i=0;i<n;i++){
        if(i==0){
            dp[i]=vec[0];
        }
        else{
            if(dp[i-1]<0){
                dp[i]=vec[i];
            }
            else{
                dp[i]=dp[i-1]+vec[i];
            }
        }
    }

    max=dp[0];
    for(int i=0;i<n;i++){
        if(max<dp[i]){
            max=dp[i];
        }
    }

    cout<<max;
    
}