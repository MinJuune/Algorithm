// 백준 버블 소트 말고
// 그냥 버블 소트임
// 백준 문제는 이렇게 하면 시간초과남

#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];

void bubble_sort(int n){
    int cnt=0;

    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                cnt++;
                
            }
        }
    }

    cout<<cnt;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    bubble_sort(N);
}
