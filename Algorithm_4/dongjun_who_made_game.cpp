// 백준 게임을 만든 동준이

#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    // 거꾸로 입력 받아
    int arr[101];
    int reverse[101];
    for(int i=0;i<N;i++){
        cin>>arr[i];
        reverse[N-i-1]=arr[i];
    }

    int cnt=0;
    // reverse에서는 인덱스가 커질수록 값은 감소해야
    for(int i=0;i<N-1;i++){
        while(reverse[i]<=reverse[i+1]){
            if(reverse[i]<=reverse[i+1]){
                reverse[i+1]--;
                cnt++;
            }
        }
    }
    
    cout<<cnt;
}