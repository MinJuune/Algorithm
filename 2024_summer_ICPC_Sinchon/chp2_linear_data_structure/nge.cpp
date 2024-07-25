// 백준 오큰수 

#include <iostream>
#include <stack>
using namespace std;

int N;
int arr[1000001];
int result[1000001];
int cur;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    stack<int> s;

    // 입력받은 값 배열에 저장
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    // result값 -1로 초기화
    for(int i=0;i<1000001;i++){
        result[i]=-1;
    }

    for(int i=0;i<N;i++){
        // 이부분 잘 이해해보기
        while(!s.empty() && arr[s.top()]<arr[i]){
            result[s.top()]=arr[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i=0;i<N;i++){
        cout<<result[i]<<" ";
    }
}

// 이중 for문 써도 break하면 괜찮을줄 알았는데
// 생각해보니까 시간복잡도는 최악의 경우이다
// stack 을 사용해서 시간 줄이기 