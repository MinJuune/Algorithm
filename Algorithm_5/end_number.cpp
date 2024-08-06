// 백준 종말의 수 

#include <iostream>
#include <algorithm>
using namespace std;

int N;

// 입력받은 수가 종말의 수인지 아닌지 확인하는 함수 
bool is_end_number(int n){
    int temp=n;
    int n_len=1;
    while(true){
        temp=temp/10;
        if(temp!=0){
            n_len++;
        }
        else{
            break;
        }
    }
    // 일단 자리수는 구함

    int rem;
    temp=n;
    int cnt_six=0;
    bool is_six=false;
    for(int i=0;i<n_len;i++){
        rem=temp%10; // 가장 오른쪽에 있는 수부터 비교 시작
        temp=temp/10;
        
        if(rem==6 && is_six==false){
            is_six=true;
            cnt_six=1;
        }
        else if(rem==6 && is_six==true){
            cnt_six++;
        }
        else if(rem!=6){
            is_six=false;
            cnt_six=0;
        }

        if(cnt_six==3){
            return true;
        }
    }
    return false;

}

// 종말의 수 구하는 함수 
void get_end_number(int n){
    int cnt=0;
    int cur=0;

    while(cnt!=N){
        // N번째 종말의 수를 찾을때까지
        // 0부터 숫자 증가시키며 찾아보기
        // 만약 종말의 수면 cnt 1씩 증가
        if(is_end_number(cur)){
            cnt++;
        }
        cur++;

    }

    cout<<cur-1;

}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    get_end_number(N);
}
