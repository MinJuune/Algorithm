// 백준 연산자 끼워넣기

#include <iostream>
using namespace std;

int N;
int arr[12];
int four_sum[4]; // 순서대로 +,-,*,/ 이고 사용할 수 있는 연산자 수 
int min_result=0;
int max_result=0;
int temp[12]; // 만들어본 조합 저장용
int result=0;
int step=0;

void oper(){
    result=arr[0];
    for(int i=0;i<N-1;i++){
        if(temp[i]==0){
            result+=arr[i+1];
        }
        else if(temp[i]==1){
            result-=arr[i+1];
        }
        else if(temp[i]==2){
            result*=arr[i+1];
        }
        else if(temp[i]==3){
            result/=arr[i+1];
        }
    }
}

// 만들수 있는 연산자 조합 다 짜기
void dfs(int cnt){
    if(cnt==N-1){
        // 계산
        oper();
        // 만약 처음 계산한 값이라면 최솟값, 최댓값 초기화
        if(step==0){
            min_result=result;
            max_result=result;
            step++;
        }
        // 그렇지 않다면 최솟값, 최댓값 계산
        else{
            if(min_result>result){
                min_result=result;
            }
            if(max_result<result){
                max_result=result;
            }
        }
        return;
    }
    else{
        for(int i=0;i<4;i++){
            // 만약 사용할 수 있는 연산자 수가 있다면
            if(four_sum[i]!=0){
                four_sum[i]--;
                temp[cnt]=i;
                dfs(cnt+1);
                four_sum[i]++;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    // 일단 입력값 전부 배열에 저장
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }  
    for(int i=0;i<4;i++){
        cin>>four_sum[i];
    }  

    dfs(0);

    cout<<max_result<<'\n'<<min_result;
}