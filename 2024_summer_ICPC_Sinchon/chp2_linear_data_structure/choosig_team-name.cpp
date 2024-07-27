// 백준 팀명 정하기 

#include <iostream>
#include <algorithm>
using namespace std;

int p, y;
string s;
int p_arr[3][2];
int y_arr[3];
string s_arr[3];
int p_max_idx;
int p_min_idx;
int p_max;
int p_min;
int p_mid_idx;


int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    p_max_idx=0;
    p_min_idx=0;
    

    for(int i=0;i<3;i++){
        cin>>p>>y>>s;
        y_arr[i]=y%100;
        p_arr[i][0]=p;
        p_arr[i][1]=i;
        s_arr[i]=s;

        if(i==0){
            p_max=p_arr[0][0];
            p_min=p_arr[0][0];
        }

        if(p_max<p){
            p_max=p;
            p_max_idx=i;
        }
        if(p_min>p){
            p_min=p;
            p_min_idx=i;
        }
    }

    sort(y_arr, y_arr+3);
    for(int i=0;i<3;i++){
        cout<<y_arr[i];
    }cout<<'\n';

    for(int i=0;i<3;i++){
        if(i!=p_max_idx && i!=p_min_idx){
            p_mid_idx=i;
        }
    }

    cout<<(s_arr[p_max_idx])[0];
    cout<<(s_arr[p_mid_idx])[0];
    cout<<(s_arr[p_min_idx])[0];
}
