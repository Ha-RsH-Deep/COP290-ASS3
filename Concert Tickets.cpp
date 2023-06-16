#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl '\n'
#define f(n) for(lli i=0;i<n;i++)
#define sort(v) sort(v.begin(),v.end())


int main(){
    lli n,m;
    cin>>n>>m;
    int a;
    vector<lli> v(n);
    f(n){ cin>>v[i];}
    sort(v);
    f(m){
        cin>>a;
        lli start = 0,mid, end = v.size()-1,result=-1;
        while(start<=end){
            mid = (start+end)/2;
            if(v[mid]<=a){
                start = mid ;
                result = v[mid];
            }
            else if(v[mid]>a){
                end = mid;
            }
        }
        v.erase(v.begin()+mid);
        cout<<result<<endl;
    }

    return 0;

}