// 백준 알고리즘 수업- 깊이 우선 탐색2

// 백준 알고리즘 수업-깊이 우선 탐색1

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int N,M,R;
vector<vector<int>> vec;
int result[100001]={0,};
bool visited[100001]={false,};

void dfs(int start){
    stack<int> s;
    // 초기화
    s.push(start);

    // 몇번째 방문했는지 
    int step=1;

    while(!s.empty()){
        // 현재위치 설정 후 스택에서 제거
        int cur=s.top();
        s.pop();
        if(!visited[cur]){
            visited[cur]=true;
            result[cur]=step++;
        }

        for(int i=0;i<vec[cur].size();i++){
            // 만약 연결되어 있는데 방문 안했으면 
            if(visited[vec[cur][i]]==false){
                s.push(vec[cur][i]);
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

    dfs(R);

    for(int i=1;i<=N;i++){
        cout<<result[i]<<'\n';
    }
}

