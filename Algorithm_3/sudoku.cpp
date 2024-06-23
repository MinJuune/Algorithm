// 백준 스도쿠
 
#include <iostream>
using namespace std;

int arr[9][9]={0,};

bool checkRow(int x,int num){
    for(int i=0;i<9;i++){
        if(arr[x][i]==num){
            return false;
        }
    }
    return true;
}

bool checkCol(int y, int num){
    for(int i=0;i<9;i++){
        if(arr[i][y]==num){
            return false;
        }
    }
    return true;
}

bool checkBox(int x, int y, int num){
    x=(x/3)*3;
    y=(y/3)*3;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[x+i][y+j]==num){
                return false;
            }
        }
    }
    return true;
}

void sudoku(int cnt){
    if(cnt==81){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<arr[i][j]<<" ";
            }cout<<'\n';
        }
        exit(0);
    }

    else{
        int x=cnt/9;
        int y=cnt%9;

        if(arr[x][y]!=0){
            sudoku(cnt+1);
            return;
        }

        for(int i=1;i<=9;i++){
            if(checkRow(x,i) && checkCol(y,i) && checkBox(x,y,i)){
                arr[x][y]=i;
                sudoku(cnt+1);
                arr[x][y]=0;
            }
        }       
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>arr[i][j];
        }
    }

    sudoku(0);
}

/*
    dfs 끝낼때 return; 과 exit(0)과의 차이점
    
    exit(0)은 프로그램을 즉시 종료
    함수 뿐 아니라 프로그램 전체 종료
    
    return은 현재 함수의 실행 종료
*/
