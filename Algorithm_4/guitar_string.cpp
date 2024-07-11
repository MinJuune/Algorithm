// 백준 기타줄

#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M;
    cin>>N>>M;
    int min_result=0;

    int arr[101][2];
    for(int i=0;i<M;i++){
        cin>>arr[i][0]>>arr[i][1];
    }   

    if(N>=6){
        int case1=0;
        int case2=0;

        // 만약 바꿔야되는 줄의 개수가 6개가 넘으면
        // 6개를 살때 최솟값을 구하기
        int min_six=1000;
        for(int i=0;i<M;i++){
            for(int j=0;j<2;j++){
                if(j==0 && arr[i][j]<min_six){
                    min_six=arr[i][j];
                }
                else if(j==1 && (arr[i][j]*6)<min_six){
                    min_six=(arr[i][j]*6);
                }
            }
        }
        
        // 우선 6개 단위로 살때의 최솟값 임시변수 case1,2에 더하기 
        int quotient=N/6;
        case1+=quotient*min_six;
        case2+=quotient*min_six;

        // 낱개로 살때 최솟값
        int min=1000;
        for(int i=0;i<M;i++){
            if(arr[i][1]<min){
                min=arr[i][1];
            }
        }

        // 나머지 낱개로 살때 최솟값 임시변수 case1에 더하기 
        int remainder=N-quotient*6;
        case1+=remainder*min;

        // 나머지 패키지로 살때 최솟값 임시변수 case2에 더하기
        case2+=min_six;

        if(case1<case2){
            min_result=case1;
        }
        else{
            min_result=case2;
        }
    }
    else{
        int min1=1000;
        for(int i=0;i<M;i++){
            if(arr[i][1]<min1){
                min1=arr[i][1];
            }
        }

        int case1=0;
        int case2=0;

        // 낱개로 구할때 최솟값
        case1+=N*min1;

        // 패키지로 구할때 최솟값
        int min2;
        for(int i=0;i<M;i++){
            if(arr[i][0]<min2){
                min2=arr[i][0];
            }
        }

        case2+=min2;

        if(case1<case2){
            min_result=case1;
        }
        else{
            min_result=case2;
        }
    }
    
    cout<<min_result;

}