// 백준 영화감독 숌

#include <iostream>
using namespace std;

//정수 길이 반환
int decom(int num){
    int temp=num;
    int size=1;
    while(temp>=10){
        size++;
        temp/= 10;
    }
    return size;
}

//종말의 수인지 확인
bool find(int num, int len){
    int temp=num;
    int next=num;
    bool six=false;
    int cnt_temp=0;

    for(int i=0;i<len;i++){
        temp=next;
        temp%=10;
        if(temp==6 && six==false){
            cnt_temp=1;
            six=true;
        }
        else if(temp==6 && six==true){
            cnt_temp++;
        }
        else{
            cnt_temp=0;
        }
        next/=10;
        if(cnt_temp==3){
            return true;
        }
    }
    return false;
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;
    int num=666;
    int len=0;
    int cnt=0;

    while(true){
        len=decom(num);
        if(find(num,len)){
            cnt++;
        }
        if(cnt==N){
            cout<<num;
            break;
        }
        else{
            num++;
        }
    }
}