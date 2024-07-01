// 백준 A->B

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int A,B;
    cin>>A>>B;

    int cnt=0;
    while(true){
        int one=B%10;
        if(A==B){
            cout<<cnt+1;
            break;
        }
        else{
            if(B==1){
                cout<<"-1";
                break;
            }
            else if(one==1){
                B=B/10;
                cnt++;
            }
            else if(B%2==0){
                B=B/2;
                cnt++;
            }
            else{
                cout<<"-1";
                break;
            }
        }
    }
}