// 백준 30 

#include <iostream>
using namespace std;
#include <algorithm>

int N;
int N_temp[10001];
int arr[10001]={0,};
bool visited[10001]={false,};
int ans=0;
bool isAns=false;

//pow 구현
int get_pow(int size, int i){
    int zero=1;
    for(int j=0;j<size-1-i;j++){
        zero=zero*10;
    }
    return zero;
}

//dfs 돌리는 함수
int dfs(int cnt, int size){
    if(cnt==size){
        for(int i=0;i<size;i++){
            int temp=get_pow(size, i);
            ans=ans+arr[i]*temp;
        }

        if(ans%30==0){
            isAns=true;
            cout<<ans;
            exit(0);
        }
        ans=0;
    }
    else{
        for(int i=0;i<size;i++){
            if(!visited[i]){
                visited[i]=true;
                arr[cnt]=N_temp[i];
                dfs(cnt+1, size);
                visited[i]=false;
            }
        }
    }
}


// 입력받은 값 길이 구하는 함수
int getsize(int n){
    int cnt=1;
    while(true){
        n/=10;
        if(n!=0){
            cnt++;
        }
        else{
            return cnt;
        }
    }
}

//입력받은 값 내림차순으로 정렬하고 각각 인덱스 저장
void save_data(int n, int size){
    for(int i=size-1;i>=0;i--){
        N_temp[i]=n%10;
        n/=10;
    }
    sort(N_temp, N_temp+size, greater<int>());
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>N;

    int size=getsize(N);

    save_data(N, size);

    int result=dfs(0, size);

    if(isAns==true){
        cout<<result;
    }
    else if(isAns==false){
        cout<<"-1";
    }
}