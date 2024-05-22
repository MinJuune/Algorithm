#include <iostream>
using namespace std;
#define MAX 9

int n,m;
int arr[MAX]={0,};
bool visited[MAX]={false,};

void dfs(int level){
    if(level==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<" ";
        }cout<<'\n';
        return ;
    }
    else{
        for(int i=1;i<=n;i++){
            if(!visited[i] && (arr[level-1]<i)){
                visited[i]=true;
                arr[level]=i;
                dfs(level+1);
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