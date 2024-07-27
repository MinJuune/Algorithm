// 백준 막대기

#include <iostream>
#include <stack>
using namespace std;

int N;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    stack<int> s;

    cin>>N;
    int num;
    for(int i=0;i<N;i++){
        cin>>num;
        s.push(num);
    }

    int stack_top=0;
    int cnt=0;
    
    while(!s.empty()){
        int cur_h=s.top();
        s.pop();
        if(cur_h>stack_top){
            cnt++;
            stack_top=cur_h;
        }
    }
    cout<<cnt;

}
