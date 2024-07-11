// BFS 기본 틀(거의 외워야됨)

#include <iostream>
using namespace std;
#include <queue>
#define X first 
#define Y second 

int board[502][502]=
{{1,1,1,0,1,0,0,0,0,0},
 {1,0,0,0,1,0,0,0,0,0},
 {1,1,1,0,1,0,0,0,0,0},
 {1,1,0,0,1,0,0,0,0,0},
 {0,1,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0},
 {0,0,0,0,0,0,0,0,0,0} };
bool vis[502][502];
int n=7;
int m=10;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
// 하 우 상 좌

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    queue<pair<int,int>> q;
    //초기화
    vis[0][0]=1;
    q.push({0,0});

    while(!q.empty()){
        pair<int, int> cur=q.front();
        q.pop();
        cout<<"("<<cur.X<<", "<<cur.Y<<") -> ";
        for(int dir=0;dir<4;dir++){
            // 상하좌우로 움직이기
            int nx=cur.X+dx[dir];
            int ny=cur.Y+dy[dir];
            if(nx<0 || nx>=n || ny<0 || ny>=m){
                continue;  // 범위에 들어왔는지 확인
            }
            if(vis[nx][ny] || board[nx][ny]!=1){
                continue;  // 방문 여부 확인
            }
            // 방문 했다고 표시
            vis[nx][ny]=1;
            q.push({nx, ny});
        }
    }
}