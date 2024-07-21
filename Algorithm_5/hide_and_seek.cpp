// 백준 숨바꼭질 

#include <iostream>
#include <queue>
using namespace std;

int N,K;
int dist[100001];

void bfs(){
    queue<int> q;
    // 초기화
    q.push(N);
    dist[N]=0;

    while(dist[K]==-1){
        // 현재위치 설정 후 큐에서 제거
        int cur=q.front();
        q.pop();

        for(int i=0;i<3;i++){
            int nN;
            if(i==0){
                nN=cur+1;
            }
            else if(i==1){
                nN=cur-1;
            }
            else if(i==2){
                nN=cur*2;
            }    

            // 범위 벗어나면 넘어가
            if(nN<0 || nN>100000){
                continue;
            }
            // 이미 방문 했으면 넘어가
            if(dist[nN]!=-1){
                continue;
            }        
            dist[nN]=dist[cur]+1;
            q.push(nN);
        }

        
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N>>K;
    for(int i=0;i<100001;i++){
        dist[i]=-1;
    }

    bfs();

    cout<<dist[K];
}