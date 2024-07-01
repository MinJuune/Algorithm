// 백준 수들의 합

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    long long S;

    cin>>S;

    int i=0;
    while(S>0){
        S-=i;
        i++;
    }
    i--;

    if(S<0){
        i--;
    }

    cout<<i;
}