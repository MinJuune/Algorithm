// 백준 행렬

#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M;
    cin>>N>>M;

    int A[51][51];
    int B[51][51];
    int temp[51][51];

    string a;
    string b;

    // 행렬 A를 배열에 저장
    for(int i=0;i<N;i++){
        cin>>a;
        for(int j=0;j<M;j++){
            if(a[j]=='0'){
                A[i][j]=0;
            }
            else if(a[j]=='1'){
                A[i][j]=1;
            }
        }
    }

    // 행렬 B를 배열에 저장
    for(int i=0;i<N;i++){
        cin>>b;
        for(int j=0;j<M;j++){
            if(b[j]=='0'){
                B[i][j]=0;
            }
            else if(b[j]=='1'){
                B[i][j]=1;
            }
        }
    }
    
    // 임시로 A행렬 복사
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            temp[i][j]=A[i][j];
        }
    }


    int cnt=0;
    // temp 행렬의 왼쪽 상단부터 원소 하나씩 비교해가기
    // 한 행 다 비교후 아래 행
    for(int i=0;i<=N-3;i++){
        for(int j=0;j<=M-3;j++){
            if(temp[i][j]!=B[i][j]){
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(temp[k][l]==1){
                            temp[k][l]=0;
                        }
                        else if(temp[k][l]==0){
                            temp[k][l]=1;
                        }
                    }
                }
                cnt++;
            }
        }
    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(temp[i][j]==B[i][j]){
                continue;
            }
            else{
                cout<<-1;
                exit(0);
            }
        }
    }
    cout<<cnt;

}