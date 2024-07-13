// 백준 토마토 7569번(3차원)

#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int M,N,H;
int arr[101][101][101];
// 거리 나타내주는 동시에 방문 여부도 확인됨
int dist[101][101][101];
// 하 우 상 좌 위 아래
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};

int result_max=0;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>M>>N>>H;
    queue<tuple<int,int,int>> q;

    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                cin>>arr[i][j][k];
                // 익은 토마토면 dist 0으로 초기화
                if(arr[i][j][k]==1){
                    q.push({j,k,i});  // x,y,z 순으로 저장
                    dist[i][j][k]=0;
                }
                else{
                    dist[i][j][k]=-1;
                }
            }
        }
    }
    // i가 높이 H
    // j가 세로 M
    // k가 가로 N
    // x,y,z 순서를 표현하려면 j,k,i

    while(!q.empty()){
        // 현재 위치 설정 후 큐에서 제거
        tuple<int,int,int> cur=q.front();
        q.pop();
        for(int i=0;i<6;i++){
            int nx=get<0>(cur)+dy[i]; // nx는 가로
            int ny=get<1>(cur)+dx[i]; // ny는 세로
            int nz=get<2>(cur)+dz[i]; // nz는 상하

            // 만약 박스 범위 벗어났으면 넘어가 
            if(nx<0 || ny<0 || nz<0 || nx>=N || ny>=M || nz>=H){
                continue;
            }
            // 만약 방문했거나 빈 칸이면 넘어가 
            if(dist[nz][nx][ny]>=0 || arr[nz][nx][ny]==-1){
                continue;
            }

            // 큐에 넣고 거리 계산
            q.push({nx,ny,nz});
            dist[nz][nx][ny]=dist[get<2>(cur)][get<0>(cur)][get<1>(cur)]+1;
        }
    }

    for(int i=0;i<H;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<M;k++){
                if(dist[i][j][k]==-1 && arr[i][j][k]!=-1){
                    cout<<-1;
                    exit(0);
                }
                else{
                    if(result_max<dist[i][j][k]){
                        result_max=dist[i][j][k];
                    }
                }
            }
        }
    }
    cout<<result_max;

    
}