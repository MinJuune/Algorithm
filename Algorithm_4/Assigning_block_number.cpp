// 백준 단지 번호 붙이기

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int arr[26][26];
bool visited[26][26];
// 하 우 상 좌
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int home_size=1;
int block_cnt=0;
vector<int> vec;

void bfs(){
    queue<pair<int,int>> q;
    // 초기화
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            // 2차원 배열을 모두 도는데 블록의 시작만 찾음
            // 블록 시작은 우선 arr이 1이어야 하고 visited가 false이어야 함
            if(arr[i][j]==1 && visited[i][j]==false){
                q.push({i,j});
                visited[i][j]=true;

                // 한 블록에 대한 탐색 시작
                while(!q.empty()){
                    // 현재위치 설정 후 큐에서 제서
                    pair<int,int> cur=q.front();
                    q.pop();



                    for(int dir=0;dir<4;dir++){
                        int nx=cur.first+dx[dir];
                        int ny=cur.second+dy[dir];

                        // 박스 범위를 벗어나면 넘어가
                        if(nx<0 || ny<0 || nx>=N || ny>=N){
                            continue;
                        }
                        // 이미 방문했거나 0으로 막혀있으면 넘어가
                        if(visited[nx][ny]==true || arr[nx][ny]==0){
                            continue;
                        }
                        // 큐에 넣고 카운팅
                        q.push({nx,ny});
                        home_size++;
                        visited[nx][ny]=true;
                    }
                }
                // 한 블록 끝

                vec.push_back(home_size);
                home_size=1;
                // 단지 수 저장
                block_cnt++;
            }
        }
    }

    cout<<block_cnt<<'\n';
    sort(vec.begin(), vec.end());
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<'\n';
    }

}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    // 지도 입력받아 배열에 저장
    cin>>N;
    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<N;j++){
            if(s[j]=='0'){
                arr[i][j]=0;
            }
            else if(s[j]=='1'){
                arr[i][j]=1;
            }
            visited[i][j]=false;
        }
    }


    bfs();
}