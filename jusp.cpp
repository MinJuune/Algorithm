#include <iostream>
using namespace std;
#include <algorithm>

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int arr[9];
    int sum=0;
    int target;
    for(int i=0;i<9;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

    target=sum-100;

    int fake1, fake2;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(i!=j){
                if(arr[i]+arr[j]==target){
                    fake1=i;
                    fake2=j;
                    break;
                }
            }
        }
    }

    arr[fake1]=0;
    arr[fake2]=0;
    sort(arr,arr+9);
    for(int i=0;i<9;i++){
        if(arr[i]!=0){
            cout<<arr[i]<<endl;
        }
    }

}