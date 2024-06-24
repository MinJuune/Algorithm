// 백준 도키도키 간식드리미

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int arr[1001];
bool visited[1001]={false,};

bool check(int n){
    stack<int> s;
    vector<int> result;

    int idx=1;
    for(int i=0;i<n;i++){
        if(arr[i]==idx){
            result.push_back(idx);
            idx++;
        }
        else{
            s.push(arr[i]);
        }

        // 중간에라도 대기줄에서 자기 순서면 나갈 수 있음
        while(!s.empty() && s.top()==idx){
            result.push_back(idx);
            s.pop();
            idx++;
        }
    }

    while(!s.empty()){
        result.push_back(s.top());
        s.pop();
    }


    for(int i=0;i<n;i++){
        if(result[i]==i+1){
            continue;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    if(check(N)==true){
        cout<<"Nice";
    }
    else{
        cout<<"Sad";
    }
    
}