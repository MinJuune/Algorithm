// 백준 queuestack

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    int A[100001];
    int B[100001];
    for(int i=0;i<N;i++){
        cin>>A[i];  // 0이면 큐, 1이면 스택
    }
    for(int i=0;i<N;i++){
        cin>>B[i];  // 원소
    }

    int M;
    cin>>M;
    int C[100001];
    for(int i=0;i<M;i++){
        cin>>C[i];
    }
    // 여기까지 입력

    queue<int> new_q;
    stack<int> temp;
    for(int i=0;i<N;i++){
        if(A[i]==0){
            temp.push(B[i]);
        }
    }

    if(temp.empty()){
        for(int i=0;i<M;i++){
            cout<<C[i]<<" ";
        }
        return 0;
    }
    

    while(!temp.empty()){
        new_q.push(temp.top());
        temp.pop();
    }

    vector<int> result;
    for(int i=0;i<M;i++){
        result.push_back(new_q.front());
        new_q.pop();
        new_q.push(C[i]);
    }
    
    for(int i=0;i<M;i++){
        cout<<result[i]<<" ";
    }
}