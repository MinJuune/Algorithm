// 백준 유기농 배추

#include <iostream>
#include <queue>
using namespace std;

int T,M,N,K;
int arr[51][51]={0,};
bool visited[51][51]={false,};
int result[2501];
int cnt=0;
// 하 우 상 좌
int dUD[4]={1,0,-1,0};
int dRL[4]={0,1,0,-1};

void dfs(){
    queue<pair<int,int>> q;

    for(int b=0;b<N;b++){
        for(int a=0;a<M;a++){
            // 만약 아직 방문 안했는데 배추가 심어져 있으면 
            // 묶음 찾기 시작
            if(arr[a][b]==1 && visited[a][b]==false){
                // 초기화
                q.push({a,b});
                visited[a][b]=true;

                while(!q.empty()){
                    // 현재위치 설정 후 큐에서 제거
                    pair<int, int> cur=q.front();
                    q.pop();
                    
                    for(int dir=0;dir<4;dir++){
                        int nx=cur.first + dRL[dir];
                        int ny=cur.second + dUD[dir];

                        // 만약 박스 밖에 있으면 넘어가
                        if(nx<0 || ny<0 || nx>=M || ny>=N){
                            continue;
                        }
                        // 만약 이미 방문 했거나 배추기 안심어져 있으면 넘어가
                        if(visited[nx][ny]==true || arr[nx][ny]==0){
                            continue;
                        }

                        q.push({nx,ny});
                        visited[nx][ny]=true;
                    }
                }
                // 한묶음 찾았으면 카운팅
                cnt++;
            }
        }   
    }

    // arr이랑 visited 전부 초기화 시켜야?
    for(int a=0;a<M;a++){
        for(int b=0;b<N;b++){
            arr[a][b]=0;
            visited[a][b]=false;
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>T;
    for(int i=0;i<T;i++){
        cin>>M>>N>>K;
        int n1, n2;
        for(int j=0;j<K;j++){
            cin>>n1>>n2;
            arr[n1][n2]=1;
        }

        dfs();
        result[i]=cnt;
        cnt=0;
    }

    for(int i=0;i<T;i++){
        cout<<result[i]<<'\n';
    }

}

/*
    bfs함수는 한 묶음만 도는 
    즉, 기능을 하나만 갖고 있는것이 좋으므로 
    다음부터는 2차원 배열을 전부 도는 것은 밖에서 하고 
    해당사항 있으면 그때 bfs 도는것으로 생각 바꾸기
*/ 