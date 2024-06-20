// 백준 분해합

#include <iostream>
using namespace std;

//정수의 길이 반환
int decom(int num){
    int temp=num;
    int size=1;
    while(temp>=10){
        size++;
        temp/= 10;
    }
    return size;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    int sum=0;
    int len=0;
    int temp=0;
    bool result=false;
    for(int i=0;i<N;i++){
        len=decom(i);
        
        sum=i;
        int next=i;
        // 생성자의 자릿수들 더하기
        for(int j=0;j<len;j++){
            temp=next%10;
            next/=10;
            sum+=temp;
        }
        if(sum==N){
            cout<<i;
            result=true;
            break;
        }
        sum=0;
   }
   if(result==false){
    cout<<0;
   }
}