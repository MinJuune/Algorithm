// 백준 평균

#include <iostream>
using namespace std;

double arr[1001];

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    int M=0;
    for(int i=0;i<N;i++){
        cin>>arr[i];
        if(M<arr[i]){
            M=arr[i];
        }
    }

    for(int i=0;i<N;i++){
        arr[i]=(arr[i]/M)*100;
    }

    double sum=0;
    double avg;
    for(int i=0;i<N;i++){
        sum+=arr[i];
    }
    avg=sum/N;
    cout<<avg;
}