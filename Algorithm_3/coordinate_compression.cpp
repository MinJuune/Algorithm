// 백준 좌표 압축

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    vector<int> vec(N);
    vector<int> temp(N);
    for(int i=0;i<N;i++){
        cin>>vec[i];
        temp[i]=vec[i];
    }
    
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    
    for(int i=0;i<N;i++){
        cout<<lower_bound(vec.begin(), vec.end(), temp[i])-vec.begin()<<" ";
    }
}

// erase, unique, lower_bound 이해