// 백준 30

#include <iostream>
using namespace std;
#include <algorithm>

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string N;
    cin>>N;

    //0이 포함되지 않으면 30의 배수를 만들 수 없음
    int size=N.size();
    bool includeZero=false;
    for(int i=0;i<size;i++){
        if(N[i]=='0'){
            includeZero=true;
        }
    }
    if(includeZero==false){
        cout<<-1;
        exit(0);
    }

    // 모든 자릿수의 합을 계산
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=N[i];
    }

    // 자릿수의 합이 3의 배수가 아니면 30의 배수를 만들 수 없음
    if(sum%3!=0){
        cout<<-1;
        exit(0);
    }

    //내림차순 정렬
    sort(N.begin(), N.end(), greater<char>());

    //출력
    cout<<N;
}