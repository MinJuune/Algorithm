// 백준 N과M(3)

#include <iostream>
using namespace std;

int N,M;
int arr[8]={0,};

void dfs(int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++){
            cout<<arr[i]<<" ";
        }cout<<'\n';
    }
    else{
        for(int i=1;i<=N;i++){
            arr[cnt]=i;
            dfs(cnt+1);
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;

    dfs(0);
}