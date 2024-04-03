#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,K;
    cin>>N>>K;
    
    int arr[10];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int count=0;
    int temp;
    for(int i=N-1;i>=0;i--){
        if(arr[i]>K){
            continue;
        }
        else{
            if(K/arr[i]==0){
                count+=K/arr[i];
                break;
            }
            else{
                count+=K/arr[i];
                K=K%arr[i];
            }
        }
    }

    cout<<count;
}