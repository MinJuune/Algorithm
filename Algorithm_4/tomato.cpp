// 백준 토마토 

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int M,N;
int arr[1001][1001];
bool visited[1001][1001]={false,};
// 하 우 상 좌
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int zero_cnt=0;
int step=0;
int zero_to_one;

void bfs(){
    queue<pair<int,int>> q;
    // 초기화
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr[i][j]==1){
                visited[i][j]=true;
                q.push({i,j});
            }
        }
    }

    int size;
    while(!q.empty()){
        size=q.size();
        // 현재위치가 여러개일때
        for(int i=0;i<size;i++){
            // 현재위치 설정 후 큐에서 제거
            pair<int,int> cur=q.front();
            q.pop();
            // 사방에 안익은 토마토가 있는지 확인
            for(int dir=0;dir<4;dir++){
                int nx=cur.first+dx[dir];
                int ny=cur.second+dy[dir];
                // 만약 박스 범위 밖에 있으면 건너 뛰기
                if(nx<0 || ny<0 || nx>=N || ny>=M){
                    continue;
                }
                // 만약 방문했거나 이미 익었거나 없으면 건너 뛰기
                if(visited[nx][ny]==true || arr[nx][ny]==1 || arr[nx][ny]==-1){
                    continue;
                }

                // 위의 예외조건에 해당 안되는 익을 토마토인 경우
                // 큐에 넣고 방문 처리 
                q.push({nx,ny});
                visited[nx][ny]=true;
                zero_to_one++;

            }
        }
        step++;
        if(zero_to_one==zero_cnt){
            cout<<step;
            exit(0);
        }
    }
    cout<<-1;

}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    // 입력받은 값 배열에 저장
    cin>>M>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
            if(arr[i][j]==0){
                zero_cnt++;
            }
        }
    }

    if(zero_cnt==0){
        cout<<0;
        exit(0);
    }

    bfs();
}