// 백준 로프

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;
    
    int num;
    vector<int> vec;
    for(int i=0;i<N;i++){
        cin>>num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end());

    int dp[100001];
    for(int i=0;i<N;i++){
        dp[i]=vec[i]*(N-i);
    }

    int max=0;
    for(int i=0;i<N;i++){
        if(max<dp[i]){
            max=dp[i];
        }
    }
    cout<<max;
}