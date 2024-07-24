// 백준 스타트와 링크 

#include <iostream>
#include <cstdlib>
using namespace std;

int N;
int arr[21][21]; // 2차원 배열에 점수 저장
bool visited[21]={false,}; 
int score1=0;
int score2=0;
int min_result=100;

void get_score(){
    // 초기화
    score1=0;
    score2=0;

    // 같은 팀끼리 점수 더하기 
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(visited[i]==true && visited[j]==true){
                score1+=(arr[i][j]+arr[j][i]);
            }
            else if(visited[i]==false && visited[j]==false){
                score2+=(arr[i][j]+arr[j][i]);
            }
        }
    }

    // 점수 차이가 제일 작은것 저장
    if(min_result>abs(score1-score2)){
        min_result=abs(score1-score2);
    }
    
}

// 모든 팀 만들어 보기 
// start 두는 이유는 중복 피하기 위함
// 중복되면 시간초과 뜸
void dfs(int start, int cnt){
    if(cnt==N/2){
        get_score();
        return;
    }
    else{
        for(int i=start;i<N;i++){
            if(!visited[i]){
                visited[i]=true;
                dfs(i+1, cnt+1);
                visited[i]=false;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    int n;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>n;
            arr[i][j]=n;
        }
    }

    dfs(0,0);

    cout<<min_result;
}