// 백준 요세푸스 문제

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,K;
    cin>>N>>K;
    queue<int> q;
    vector<int> result;

    // 초기화
    for(int i=1;i<=N;i++){
        q.push(i);
    }
    // K번째마다 제거하기 위해 카운팅
    int cnt=1;
    
    while(!q.empty()){
        if(cnt==K){
            result.push_back(q.front());
            q.pop();
            cnt=1;
        }
        else{
            cnt++;
            q.push(q.front());
            q.pop();
        }
    }
    

    cout<<"<";
    for(int i=0;i<N;i++){
        if(i!=N-1){
            cout<<result[i]<<", ";
        }
        else{
            cout<<result[i];
        }
    }
    cout<<">";
}