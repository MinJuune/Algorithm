// 백준 N과 M(1)

#include <iostream>
using namespace std;
#define MAX 9

int n,m;
int arr[MAX]={0,};
bool visited[MAX]={false,};

void dfs(int cnt){ // cnt는 현재까지 선택된 숫자의 갯수
    if(cnt==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }cout<<'\n';
        return;
    }
    else{
        for(int i=1;i<=n;i++){
            if(!visited[i]){
                visited[i]=true;
                arr[cnt]=i;
                dfs(cnt+1);
                visited[i]=false;
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin>>n>>m;    
    dfs(0);
}

/* 
    조합의 개수를 구하는 문제이므로, dfs를 활용하여 풀이가 가능하다. 
    각 숫자는 순열에서 딱 한번만 사용되므로, 각 숫자를 인덱스로 가지는
    bool형 배열인 visited를 선언하고, 
    해당 숫자를 뽑았는지 유무를 저장한다. 
    숫자를 앞에서부터 한개씩 뽑아가면서 visited가 M개만큼 true가 되면, 
    출력을 해주는 재귀함수를 활용하면 된다.
*/