// 백준 체스판 다시 칠하기

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N,M;
    cin>>N>>M;
    char arr[50][50];
    int cnt1=0;
    int cnt2=0;
    int min=64;
    int temp=0;

    char arr_b[8][8]={
        'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W'
    };

    char arr_w[8][8]={
        'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B',
		'B','W','B','W','B','W','B','W',
		'W','B','W','B','W','B','W','B'
    };

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>arr[i][j];
        }
    }

    for(int i=0;i<N-7;i++){
        for(int j=0;j<M-7;j++){
            cnt1=0;
            cnt2=0;

            for(int k=0;k<8;k++){
                for(int l=0;l<8;l++){
                    if(arr[k+i][l+j]!=arr_b[k][l]){
                        cnt1++;
                    }
                    if(arr[k+i][l+j]!=arr_w[k][l]){
                        cnt2++;
                    }
                }
            }

            if(cnt1<cnt2){
                temp=cnt1;
            }else{
                temp=cnt2;
            }
            if(min>temp){
                min=temp;
            }
        }
    }

    cout<<min;
}