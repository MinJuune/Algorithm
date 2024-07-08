// 백준 거스름돈

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int n;
    cin>>n;

    int five;
    int two;
    if(n==1 || n==3){
        cout<<"-1";
        exit(0);
    }
    else if(n%5==0){
        five=n/5;
        two=0;
    }    
    else if(n%2==0){
        if((n/5)%2==1){
            five=n/5-1;
            two=(n-five*5)/2;
        }
        else if((n/5)%2==0){
            five=n/5;
            two=(n-five*5)/2;
        }
    }
    else{
        if((n/5)%2==1){
            five=n/5;
            two=(n-five*5)/2;
        }
        else if((n/5)%2==0){
            five=n/5-1;
            two=(n-five*5)/2;
        }
    }
    cout<<five+two;

    
}
