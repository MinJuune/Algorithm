// 백준 미로 탐색

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int N,M;
int arr[101][101];
bool visited[101][101]={false,};
// 하 우 상 좌
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int dist[101][101]={1,};

void bfs(){
    queue<pair<int,int>> q;
    visited[0][0]=true;
    q.push({0,0});

    while(!q.empty()){
        pair<int,int> cur=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            // 옮길 좌표 구함
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];

            // 박스 범위 벗어나거나
            if(nx<0 || ny<0 || nx>=N || ny>=M){
                continue;
            }
            // 방문했거나 막혀있으면 넘어가
            if(visited[nx][ny]==true || arr[nx][ny]==0){
                continue;
            }

            // 만약 박스 범위 안이고 방문 안했고 안막혀있으면
            // 방문 표시, 큐에 넣어 
            visited[nx][ny]=true;
            q.push({nx,ny});

            dist[nx][ny]=dist[cur.first][cur.second]+1;
        }
    }

    cout<<dist[N-1][M-1];
}


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    
    cin>>N>>M;

    // 미로 배열로 입력 받기
    string str;
    for(int i=0;i<N;i++){
        cin>>str;
        for(int j=0;j<M;j++){
            if(str[j]=='0'){
                arr[i][j]=0;
            }
            else{
                arr[i][j]=1;
            }
        }
    }

    bfs();
}