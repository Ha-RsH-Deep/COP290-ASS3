#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl '\n'
#define f(n) for(lli i=0;i<n;i++)
#define sort(v) sort(v.begin(),v.end())

int main(){
    lli n,x;
    cin>>n>>x;
    vector<int> v(n);
    f(n){ cin>>v[i];}
    sort(v);
    int start=0,end =n-1,result=0;
    while(start<=end){
        if(v[start]+v[end]<=x || start==end){
            result++;
            start++;
        end--;
        }
        else{
            result +=1;
            end--;
        }
        
    }
    cout<<result<<endl;

}