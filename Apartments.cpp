#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define lli long long int
#define f(n) for(lli i=0;i<n;i++)
#define sort(v) sort(v.begin(),v.end())


int main(){
    lli n,m,k;
    cin>>n>>m>>k;
    vector<lli> v1(n);
    vector<lli> v2(m);
    f(n){ cin>>v1[i];}
    sort(v1);
    f(m){ cin>>v2[i];}
    sort(v2);
    int result =0;
    int i=0,j=0;
    while(i<n && j<m){
        if(abs(v1[i]-v2[j]) <= k){
            result++;
            i++;
            j++;
        }
        else if(v1[i] > v2[j]+k ){
            j++;
        }
        else{
            i++;
        }
    }
    cout<<result<<endl;

}