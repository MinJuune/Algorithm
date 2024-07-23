// 백준 과제 안내신분..?

#include <iostream>
using namespace std;

bool arr[31]={false,};

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    for(int i=0;i<28;i++){
        cin>>n;
        arr[n]=true;
    }
    
    for(int i=1;i<=30;i++){
        if(arr[i]==false){
            cout<<i<<'\n';
        }
    }
    
}