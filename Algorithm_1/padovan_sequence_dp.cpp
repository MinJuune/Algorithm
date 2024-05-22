// 백준 파도반 수열

#include <iostream>
using namespace std;


long long dp[101]={0};

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int T;
    cin>>T;

    int N;
    for(int i=0;i<T;i++){
       
        cin>>N;
        for(int j=1;j<N+1;j++){
            if(j==1 || j==2 || j==3){
                dp[j]=1;
            }
            else if(j==4 || j==5){
                dp[j]=2;
            }
            else{
                for(int k=6;k<N+1;k++){
                    dp[k]=dp[k-1]+dp[k-5];
                }
            }
        }

        cout<<dp[N]<<'\n';
    }
}

/*
    그냥 일단 나열해보기
    int의 범위는  2,147,483,647 까지
    답의 범위도 잘 생각하기
*/



    