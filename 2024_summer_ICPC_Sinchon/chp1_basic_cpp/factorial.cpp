// 백준 팩토리얼

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    int result=1;
    for(int i=1;i<=N;i++){
        result *= i;
    }
    cout<<result;
}