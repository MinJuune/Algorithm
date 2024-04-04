// 백준 분수찾기

#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int X;
    cin>>X;

    vector<int> vec;
    int k=1;
    int i=0;
    while(true){
        vec.push_back(k+i);
        k+=i;
        i++;
        if(k>10000000){
            break;
        }
    }
    
    i=0;
    while(true){
        if(X>=vec[i] && X<vec[i+1]){
            break;
        }
        else{
            i++;
        }
    }

    int l,r;
    if(i==0){
        cout<<1<<"/"<<1;
    }
    else{
        if(i%2==0){
            l=(i+1)-(X-vec[i]);
            r=1+(X-vec[i]);
            cout<<l<<"/"<<r;
        }
        else{
            l=1+(X-vec[i]);
            r=(i+1)-(X-vec[i]);
            cout<<l<<"/"<<r;
        }
    }
}