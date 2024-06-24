// 백준 그림

#include <iostream>
using namespace std;
#include <queue>
#define X first 
#define Y second 

int n,m;
int board[501][501];
bool visited[502][502]={false,};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }

    int max=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]==0 || visited[i][j]==true){
                continue;
            }
            cnt++;
            queue<pair<int,int>> q;
            
            // 초기화
            visited[i][j]=true;
            q.push({i,j});

            int max_temp=0;

            while(!q.empty()){
                max_temp++;
                pair<int,int> cur=q.front();
                q.pop();
                
                for(int dir=0;dir<4;dir++){
                    int nx=cur.X + dx[dir];
                    int ny=cur.Y + dy[dir];

                    if(nx<0 || nx>=n || ny<0 || ny>=m){
                        continue;
                    }
                    if(visited[nx][ny]==true || board[nx][ny]==0){
                        continue;
                    }

                    visited[nx][ny]=true;
                    q.push({nx,ny});
                }
            }
            if(max_temp>max){
                max=max_temp;
            }
        }
    }
    cout<<cnt<<'\n'<<max;
    
}