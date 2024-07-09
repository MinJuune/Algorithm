// 백준 폴리오미노

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    string str;
    cin>>str;

    char result[50];
    int cnt=0;
    int size=0;
    int A,B;
    for(int i=0;i<str.size();i++){
        // X의 부분 길이를 구함
        while(str[i]=='X'){
            size++;
            i++;
        }

        // 만약 X의 수가 홀수개인 부분이 있으면 그대로 종료
        if(size%2==1){
            cout<<"-1";
            exit(0);
        }

        // X의 수가 짝수개이면
        // X의 수가 4개인 A부분과 2개인 B부분으로 나눔
        else{
            A=size/4;
            B=(size-A*4)/2;
        }

        // result배열에 저장
        for(int j=0;j<A;j++){
            if(A!=0){
                result[cnt]='A';
                cnt++;
            }
        }

        for(int j=0;j<B;j++){
            if(B!=0){
                result[cnt]='B';
                cnt++;
            }
        }
        
        size=0;

        if(str[i]=='.'){
            result[cnt]='.';
            cnt++;
        }
    }

    for(int i=0;i<cnt;i++){
        if(result[i]=='A'){
            for(int j=0;j<4;j++){
                cout<<result[i];
            }
        }
        else if(result[i]=='B'){
            for(int j=0;j<2;j++){
                cout<<result[i];
            }
        }
        else if(result[i]=='.'){
            cout<<result[i];
        }
    }
}