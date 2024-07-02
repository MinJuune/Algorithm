// 백준 한수

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    int temp;
    int cnt=99;
    if(N<100){
        cnt=N;
    }
    else if(100<=N && N<1000){   
        for(int i=100;i<=N;i++){
            temp=i;
            int first=temp%10;
            temp/=10;
            int second=temp%10;
            temp/=10;
            int third=temp%10;
            temp/=10;

            if(third-second==second-first){
                cnt++;
            }
        }
    }
    else if(N==1000){
        cnt=144;
    }

    cout<<cnt;
}