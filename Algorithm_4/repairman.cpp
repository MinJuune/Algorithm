// 백준 수리공 항승

#include <iostream>
using namespace std;
#include <algorithm>

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,L;
    cin>>N>>L;

    // 입력
    int arr[1001];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    int cnt=0;

    // 정렬
    sort(arr, arr+N);

    int temp;
    // 테이프 길이랑 물이 새는 길이 비교
    for(int i=0;i<N;i++){
        temp=i;
        while(arr[temp]+L>arr[i+1] && i<N-1){
            i++;
        }
        cnt++;
    }

    cout<<cnt;
}