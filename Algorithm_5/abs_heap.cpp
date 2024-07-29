// 백준 절댓값 힘

#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int N;

// c++은 우선순위 큐에서 최대힙을 제공하는데
// 이 문제는 최소힙 문제 
// 구현을 바꿔줘야하므로 이 코드 필요
// 두 숫자 비교하여 우선순위 결정
// 우선순위 큐에서 숫자들을 정렬할때 사용
struct compare{
    bool operator()(int a, int b){
        // 절댓값이 같으면
        if(abs(a)==abs(b)){
            // 원래값이 더 작은쪽이 우선순위가 높음
            // a>b일때 true를 반환하여 a의 우선순위를 낮춤
            return a>b;
        }
        // 절댓값이 다르면 절댓값이 작은쪽이 우선순위가 높음
        // abs(a)>abs(b)일때 true를 반환하여 a의 우선순위를 낮춤
        return abs(a)>abs(b);
    }
};

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;
    int num;
    priority_queue<int, vector<int>, compare> pq;

    for(int i=0;i<N;i++){
        cin>>num;
        if(num!=0){
            pq.push(num);
        }
        else{
            if(pq.empty()){
                cout<<"0"<<'\n';
            }
            else{
                cout<<pq.top()<<'\n';
                pq.pop();
            }
        }
    }
   
}
 
// 아직 우선순위 큐 정확하게는 모르겠음
// 좀더 공부할 필요 있음