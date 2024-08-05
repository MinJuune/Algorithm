// 백준 수들의합2

#include <iostream>
using namespace std;

int N,M;
int arr[10001];

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int sum=0;
    int cnt=0;
    
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            sum+=arr[j];
            if(sum==M){
                cnt++;
                break;
            }
            else if(sum<M){
                continue;
            }
            else if(sum>M){
                break;
            }
        }
        sum=0;
    }

    cout<<cnt;
    
}
