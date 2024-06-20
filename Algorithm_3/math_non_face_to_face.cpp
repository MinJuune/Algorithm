// 백준 수학은 비대면 강의입니다

#include <iostream>
using namespace std;

int main(){
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    int a,b,c,d,e,f;
    cin>>a>>b>>c>>d>>e>>f;

    int x,y;
    x=(c*e-b*f)/(a*e-b*d);
    y=(c*d-a*f)/(b*d-a*e);

    cout<<x<<" "<<y;
}