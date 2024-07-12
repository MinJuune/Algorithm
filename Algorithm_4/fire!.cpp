// 백준 불!

#include <iostream>
#include <string>
#include <queue>
using namespace std;

int R,C;
char arr[1001][1001];
int distF[1001][1001];
int distJ[1001][1001];

// 하 우 상 좌
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};



int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    //dist 전부 -1로 초기화
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            distF[i][j]=-1;
        }
    }
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            distJ[i][j]=-1;
        }
    }

    cin>>R>>C;

    queue<pair<int, int>> qJ;
    queue<pair<int, int>> qF;

    // 미로 입력받고 배열에 저장
    // 지훈이 초기위치 저장, 불이 난 위치 저장
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            cin>>arr[i][j];
            if(arr[i][j]=='J'){
                qJ.push({i,j});
                distJ[i][j]=0;
            }
            else if(arr[i][j]=='F'){
                qF.push({i,j});
                distF[i][j]=0;
            }
        }
    }

    // 불 번지는거 먼저
    while(!qF.empty()){   
        pair<int,int> cur_F=qF.front();
        qF.pop();
        for(int i=0;i<4;i++){
            int nx=cur_F.first+dx[i];
            int ny=cur_F.second+dy[i];

            // 벽 만나면 불 안번짐
            if(arr[nx][ny]=='#'){
                continue;
            }
            // 박스 범위 벗어나면 불 안번짐
            if(nx<0 || ny<0 || nx>=R || ny>=C){
                continue;
            } 
            
            if(distF[nx][ny]>=0){
                continue;
            }

            distF[nx][ny]=distF[cur_F.first][cur_F.second]+1;
            qF.push({nx,ny});
        }            
    }


    while(!qJ.empty()){
        // 지훈이 도망가는거
        pair<int,int> cur_J=qJ.front();
        qJ.pop();
        for(int i=0;i<4;i++){
            int nx=cur_J.first+dx[i];
            int ny=cur_J.second+dy[i];

            // 탈출 성공
            if(nx<0 || ny<0 || nx>=R || ny>=C){
                cout<<distJ[cur_J.first][cur_J.second]+1;
                exit(0);
            }
            // 탈출 실패
            else{
                // 벽 만나면 도망 못감
                if(arr[nx][ny]=='#'){
                    continue;
                }
                // 불 번진곳이면 도망 못감
                if(distJ[nx][ny]>=0){
                    continue;
                }
                if(distF[nx][ny]!=-1 && distF[nx][ny]<=distJ[cur_J.first][cur_J.second]+1){
                    continue;
                }

                distJ[nx][ny]=distJ[cur_J.first][cur_J.second]+1;
                qJ.push({nx,ny});
            }   
        }
    }
    cout<<"IMPOSSIBLE";

    
}