#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin>>n;
    n=1000-n;

    int cnt=0;

    if(n>=500){
        cnt++;
        n-=500;
    }

    int num_100=n/100;
    cnt+=num_100;
    n-=100*num_100;

    if(n>=50){
        cnt++;
        n-=50;
    }

    int num_10=n/10;
    cnt+=num_10;
    n-=10*num_10;

    if(n>=5){
        cnt++;
        n-=5;
    }

    int num_1=n;
    cnt+=num_1;
    n-=num_1;

    cout<<cnt;
}