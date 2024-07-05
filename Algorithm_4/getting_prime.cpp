// 백준 소수 구하기

/*
    그냥 소수를 구하면 시간초과 나므로
    에라토스테네스의 체 구현가기 
    범위 내에서 i=2부터 i*i<num까지
    i를 자기의 2배수부터 모든 배수 0으로 바꿈
    i를 i*i<num 될때까지 증가시키면서 0으로 바꾼다
*/

#include <iostream>
using namespace std;
#include <algorithm>

int arr[1000001];

void solve(int m, int n){
    for(int i=2;i<=n;i++){
        arr[i]=i;
    }

    for(int i=2;i*i<=n;i++){
        if(arr[i]==0){
            continue;
        }
        else{   
            for(int j=2*i;j<=n;j=j+i){
                arr[j]=0;
            }
        }
    }

    for(int i=m;i<=n;i++){
        if(arr[i]!=0){
            cout<<i<<'\n';
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int M,N;
    cin>>M>>N;

    solve(M,N);
}