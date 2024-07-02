// 백준 덩치

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    int x,y;
    int arr[51][2];
    for(int i=0;i<N;i++){
        cin>>x>>y;
        arr[i][0]=x;
        arr[i][1]=y;
    }

    int cnt=1;
    int result[51];
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][0]<arr[j][0] && arr[i][1]<arr[j][1]){
                cnt++;
            }
        }
        result[i]=cnt;
        cnt=1;
    }

    for(int i=0;i<N;i++){
        cout<<result[i]<<' ';
    }
}