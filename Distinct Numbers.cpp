#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lli long long int
#define f(n) for(int i=0;i<n;i++)

int main(){
    int n,a;
    cin>>n;
    set<int> s;
    f(n){
        cin>>a;
        s.insert(a);

    }
    cout<<s.size()<<endl;
}