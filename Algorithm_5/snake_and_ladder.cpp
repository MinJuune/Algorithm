// 백준 뱀과 사다리 게임

#include <iostream>
#include <queue>
using namespace std;

int N,M;
int arr[101]={0,};
int dist[101];
// 1,2,3,4,5,6
int move_dice[6]={1,2,3,4,5,6};
int up_size=0;
int down_size=0;

void bfs(){
    queue<int> q;
    // 초기화
    q.push(1);
    dist[1]=0;

    while(!q.empty()){
        // 현재위치 설정 후 큐에서 제거
        int cur=q.front();
        q.pop();

        for(int i=0;i<6;i++){
            int ncur=cur+move_dice[i];

            // 만약 100번을 넘어간 칸이면 넘어가
            if(ncur>100){
                continue;
            }
            // 만약 이미 방문한 칸이면 넘어가 
            if(dist[ncur]!=-1){
                continue;
            }
            // 아래 코드부터는 방문하지 않고 
            // 100번 이내에 있는 유효한 칸

            // 이동해야되는 칸이면 이동
            if(arr[ncur]!=0){
                ncur=arr[ncur];
            }

            // 이동했을수도 있으니까 다시 방문한 칸인지 확인
            if(dist[ncur]==-1){
                q.push(ncur);
                dist[ncur]=dist[cur]+1;
            }

            // 이동 끝났을때 100번째 칸이면 출력하고 끝내
            if(ncur==100){
                cout<<dist[ncur];
                exit(0);
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    // 사다리 초기화
    for(int i=0;i<101;i++){
        arr[i]=0;
    }

    cin>>N>>M;
    int x,y;
    for(int i=0;i<N+M;i++){
        cin>>x>>y;
        arr[x]=y;
    }

    // 거리 초기화
    for(int i=0;i<101;i++){
        dist[i]=-1;
    }
    

    bfs();
}