// 백준 수 정렬하기2

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000001];
int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    sort(arr, arr+N);
    
    for(int i=0;i<N;i++){
        cout<<arr[i]<<'\n';
    }
   
}
