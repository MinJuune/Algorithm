// 백준 에라토스테네스의 체

#include <iostream>
using namespace std;

void solve(int n,int k){
    int arr[1001];
    for(int i=1;i<=n;i++){
        arr[i]=i;
    }

    int cnt=0;
    for(int i=2;i<=n;i++){
        if(arr[i]==0){
            continue;
        }

        else{
            for(int j=i;j<=n;j=j+i){
                if(arr[j]==0){
                    continue;
                }
                else{
                    cnt++;
                    if(cnt==k){
                        cout<<arr[j];
                    }
                    else{
                        arr[j]=0;
                    }
                }
            }
        }
    }


}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,K;
    cin>>N>>K;

    solve(N,K);
}