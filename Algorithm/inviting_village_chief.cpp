// 백준 이장님 초대

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int N;
    cin>>N;

    vector<int> vec;
    int num;
    for(int i=0;i<N;i++){
        cin>>num;
        vec.push_back(num);
    }

    sort(vec.begin(), vec.end(), greater<int>());

    int result=0;
    int max=0;
    for(int i=N-1;i>=0;i--){
        if(max < (i+1)+vec[i]+1){
            max=(i+1)+vec[i]+1;
        }
    }

    cout<<max;
}