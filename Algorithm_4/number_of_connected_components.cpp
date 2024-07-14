// 백준 연결요소의 개수

#include <iostream>
#include <queue>
using namespace std;

int N,M;
bool arr[1001][1001]={false,};
bool visited[1001]={false,};
bool keep=true;

void bfs(int start){
    queue<int> q;
    // 초기화
    q.push(start);
    visited[start]=true;

    while(!q.empty()){
        // 현재위치 설정후 큐에서 제거 
        int cur=q.front();
        q.pop();

        for(int k=1;k<=N;k++){
            // 만약 현재 노드랑 연결되어 있고 
            // 아직 방문 안했으면 큐에 추가  
            if(arr[cur][k]==true && visited[k]==false){
                q.push(k);
                visited[k]=true;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M;
    int n1,n2;
    for(int i=0;i<M;i++){
        cin>>n1>>n2;
        arr[n1][n2]=true;
        arr[n2][n1]=true;
    }
    
    int cnt=0;
    for(int i=1;i<=N;i++){
        if(visited[i]==false){
            bfs(i);
            cnt++;
        }
    }

    cout<<cnt;
}