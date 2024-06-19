// 백준 주유소

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;
    
    // dist,price 값이 1이상 1,000,000,000 이하이므로
    // dist*price값이 int 범위인 2,000,000,000을 넘어갈 가능성이 커서 
    // int가 아닌 long long 자료형으로 설정해줘야 함
    long long dist[100001];
    long long price[100001];
    for(int i=0;i<N-1;i++){
        cin>>dist[i];
    }
    for(int i=0;i<N;i++){
        cin>>price[i];
    }

    long long temp=price[0];
    long long sum=dist[0]*price[0];
    for(int i=0;i<N-1;i++){
        if(temp>price[i+1]){
            sum += dist[i+1]*price[i+1];
            temp=price[i+1];
        }
        else{
            sum += dist[i+1]*temp;
        }
    }

    cout<<sum<<'\n';
}