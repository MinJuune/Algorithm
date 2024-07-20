// 백준 알고리즘 수업-너비 우선 탐색1

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N,M,R;
vector<vector<int>> vec;
int result[100001]={0,};
bool visited[100001]={false,};

void bfs(int start){
    queue<int> q;
    // 초기화
    q.push(start);
    visited[start]=true;

    // 몇번째 출력될건지
    int step=1;

    while(!q.empty()){
        // 현재위치 설정 후 큐에서 제거
        int cur=q.front();
        q.pop();
        result[cur]=step;
        step++;

        for(int i=0;i<vec[cur].size();i++){
            // 만약 방문을 안했으면
            if(visited[vec[cur][i]]==false){
                q.push(vec[cur][i]);
                visited[vec[cur][i]]=true;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>M>>R;
    vec.resize(N+1);
    int n1,n2;
    for(int i=0;i<M;i++){
        cin>>n1>>n2;
        vec[n1].push_back(n2);
        vec[n2].push_back(n1);
    }

    for(int i=1;i<=N;i++){
        sort(vec[i].begin(), vec[i].end());
    }

    bfs(R);

    for(int i=1;i<=N;i++){
        cout<<result[i]<<'\n';
    }
}

/*
    N 입력 받으면
    벡터 크기를 .resize(N+1)로 초기화 시켜주기 
*/