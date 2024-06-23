// 백준 n과m(2)

#include <iostream>
using namespace std;

int N,M;
int arr[9]={0,};
bool visited[9]={false,};

void dfs(int cnt){
    if(cnt==M){
        for(int i=0;i<M;i++){
            cout<<arr[i]<<" ";
        }cout<<'\n';
    }
    else{
        for(int i=1;i<=N;i++){
            if(!visited[i] && (arr[cnt-1]<i)){
                arr[cnt]=i;
                visited[i]=true;
                dfs(cnt+1);
                visited[i]=false;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;

    dfs(0);
}