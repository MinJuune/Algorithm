// 백준 팰린드롬 만들기

#include <iostream>
using namespace std;
#include <stack>
#include <algorithm>

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string str;
    cin>>str;
    
    stack<char> s;

    // 사전순 정렬
    sort(str.begin(), str.end());

    int odd=0;
    int temp=1;
    char odd_center;
    // 우선 팰린드롬을 만들수 있는지 확인
    // 홀수인것의 개수가 2개 이상이면 만들지 못함
    for(int i=0;i<str.size();i++){
        if(str[i]==str[i+1]){
            temp++;
        }    
        else{
            if(temp%2==1){
                odd++;
                odd_center=str[i];
            }
            temp=1;
        }
    }

    if(odd>1){
        cout<<"I'm Sorry Hansoo";
        exit(0);
    }
    else{
        // 절반은 사전순으로 출력
        // 절반은 스택에 저장후 팰린드롬에 맞게 출력
        int size=1;
        for(int i=0;i<str.size();i++){
            if(str[i]==str[i+1]){
                size++;
            }
            else{
                for(int j=0;j<size/2;j++){
                    cout<<str[i];
                    s.push(str[i]);
                }
                size=1;
            }
        }
    }

    // 만약 홀수인것이 한개 있으면 가운데에 출력
    if(odd==1){
        cout<<odd_center;
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

}