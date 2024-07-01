// 백준 카드 정렬하기

#include <iostream>
using namespace std;
#include <queue>
#include <vector>
#include <algorithm>

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    priority_queue<int, vector<int>, greater<int>> min_pq;

    int num;
    for(int i=0;i<N;i++){
        cin>>num;
        min_pq.push(num);
    }

    int sum=0;
    while(min_pq.size()>1){
        int first=min_pq.top();
        min_pq.pop();

        int second=min_pq.top();
        min_pq.pop();
        
        sum+=(first+second);

        min_pq.push(first+second);  
    }

    cout<<sum;

    
    
}