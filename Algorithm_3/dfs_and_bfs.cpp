// 백준 DFS와 BFS

#include <iostream>
#include <queue>
#include <stack>
using namespace std; 

int board[1001][1001];
bool vis[1001];
int N,M;
int idx=0;

//스택으로 bfs 구현
void bfs(int start){
    queue<int> q;
    
    //초기화
    q.push(start);
    vis[start]=true;

    vector<int> result;
    while(!q.empty()){
        int cur=q.front();
        result.push_back(q.front());
        q.pop();
        
        for(int i=1;i<=N;i++){
            if(board[cur][i]==1 && vis[i]==false){
                q.push(i);
                vis[i]=true;
            }
        }
    }

    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
}

//재귀로 dfs 구현
void dfs(int target){
    vis[target]=true;
    cout<<target<<" ";
        
    for(int i=1;i<=N;i++){
        if(board[target][i]==1 && vis[i]==false){
            dfs(i);
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int start;
    cin>>N>>M>>start;
    int n1,n2;
    for(int i=0;i<M;i++){
        cin>>n1>>n2;
        board[n1][n2]=1;
        board[n2][n1]=1;
    }

    dfs(start);
    for(int i=0;i<1001;i++){
        vis[i]=false;
    }
    cout<<'\n';
    bfs(start);
}