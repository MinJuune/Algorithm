#include <iostream>
using namespace std;
#include <algorithm>

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    int arr[11];
    int result[11];
    bool visited[11]={false,};
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }

    for(int i=0;i<N;i++){
        int target=arr[i];
        int cnt=0;
        while(true){
            if(visited[cnt]==false){
                if(target==0){
                    result[cnt]=i+1;
                    visited[cnt]=true;
                    break;
                }   
                else{
                    cnt++;
                    target--;
                }
            }
            else if(visited[cnt]==true){
                cnt++;   
            }
        }
    }
    
    for(int i=0;i<N;i++){
        cout<<result[i]<<" ";
    }

}