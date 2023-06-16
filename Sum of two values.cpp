#include<bits/stdc++.h>
using namespace std;
#define lli long long int
#define endl '\n'
#define f(i,n) for(lli i=0;i<n;i++)
#define f2(j,i,n) for(lli j=i+1;j<n;j++)
#define s_sort(v) sort(v.begin(),v.end())
#define reverse_sort(v) sort(v.rbegin(),v.rend())
#define p pair<lli,lli>
#define F first
#define S second


bool sortbysec(const pair<lli,lli>&a, const pair<lli,lli>&b){
    return (a.S< b.S);
}

void solve(){
    lli n , sum ;
    cin>>n>>sum;
    vector<p> v(n);
    f(i,n){
        cin>>v[i].F;
        v[i].S = i;
    }
    sort(v.begin(),v.end());
    lli start = 0 , end = n-1;
    lli a = INT_MAX,b= INT_MAX;
    while(start<end){
        if(v[start].F+ v[end].F == sum){
            a = v[start].S;
            b =  v[end].S;
            break;
        }
        else if(v[start].F+ v[end].F > sum){
            end--;
        }
        else{
            start++;
        }
    }
    if(a != INT_MAX){
        cout<<a+1<<" "<<b+1<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        auto start_timer = chrono::high_resolution_clock::now();
    #endif
    cout<<fixed<<setprecision(20);
    solve();
    
    
    #ifdef LOCAL
        auto stop_timer = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop_timer - start_timer);
        cerr << "Time taken : " << ((long double)duration.count())/((long double) 1e9) <<"s "<< endl;
    #endif
    return 0;
}