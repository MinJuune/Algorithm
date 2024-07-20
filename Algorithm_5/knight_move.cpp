// 백준 나이트의 이동

#include <iostream>
#include <queue>
using namespace std;

int T;
int I;
int arr[2][2];
int dist[301][301];
bool next_step=false;

// 우측 하단 부터 
int dx[8]={2,1,-1,-2,-2,-1,1,2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

void bfs(){
    queue<pair<int,int>> q;
    // 초기화
    q.push({arr[0][0], arr[0][1]});
    dist[arr[0][0]][arr[0][1]]=0;

    while(!q.empty()){
        // 현재 위치 설정 후 큐에서 제거
        pair<int,int> cur=q.front();
        q.pop();

        for(int i=0;i<8;i++){
            int nx=cur.first+dx[i];
            int ny=cur.second+dy[i];

            // 만약 박스 범위 밖에면 넘어가
            if(nx<0 || ny<0 || nx>=I || ny>=I){
                continue;
            }
            // 만약 방문을 이미 했으면 넘어가
            if(dist[nx][ny]!=-1){
                continue;
            }

            q.push({nx,ny});
            dist[nx][ny]=dist[cur.first][cur.second]+1;

            if(nx==arr[1][0] && ny==arr[1][1]){
                cout<<dist[nx][ny]<<'\n';
                next_step=true;
                break;
            }
        }
        if(next_step==true){
            break;
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>I;
        // arr[0]은 시작 좌표
        // arr[1]은 도착 좌표
        cin>>arr[0][0]>>arr[0][1];
        cin>>arr[1][0]>>arr[1][1];
    
        // dist 전부 -1로 초기화
        for(int i=0;i<301;i++){
            for(int j=0;j<301;j++){
                dist[i][j]=-1;
            }
        }

        if(arr[0][0]==arr[1][0] && arr[0][1]==arr[1][1]){
            cout<<0<<'\n';
        }
        else{
            bfs();
        }
        next_step=false;
    }
}