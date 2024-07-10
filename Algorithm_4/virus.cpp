// 백준 바이러스 

#include <iostream>
using namespace std;
#include <algorithm>
#include <queue>

int node, edge;
bool arr[101][101]={false,};
bool visited[101]={false,};

// 큐로 bfs 구현
void bfs(int start){
    int cnt=0;
    queue<int> q;
    q.push(start);
    visited[start]=true;
    // 1번 노드부터 시작해서 1번노드 방문 표시,큐에 넣기
    while(!q.empty()){
        for(int i=1;i<=node;i++){
            if(arr[q.front()][i]==true){
                if(visited[i]==false){
                    // 만약 연결되어 있고, 방문을 안한 노드면
                    q.push(i); // 큐에 넣고
                    visited[i]=true; // 방문 표시 하고 
                    cnt++;  // 카운트
                }
            }
        }
        q.pop(); 
        // 각 노드에서 연결된 노드를 큐에 다 집어 넣으면 
        // 그 노드는 큐에서 제거
    }

    cout<<cnt;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>node;
    cin>>edge;
    int n1,n2;
    for(int i=0;i<edge;i++){
        cin>>n1>>n2;
        arr[n1][n2]=true;
        arr[n2][n1]=true;
    }
    // 2차원 인접행렬로 network 표현


    bfs(1);
}