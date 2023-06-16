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



void solve(){
    lli n;
    cin>>n;
    vector<lli> starti;
    vector<lli> endi;
    f(i,n){
        lli a,b;
        cin>>a>>b;
        starti.push_back(a);
        endi.push_back(b);
    }
    sort(starti.begin(),starti.end());
    sort(endi.begin(),endi.end());

    lli ans = INT_MIN;
    lli c =0;
    lli si =0,ei=0;
    while(si<n){
        if(endi[ei]<starti[si]){
            ei++;
            c--;
        }
        else if(endi[ei]>=starti[si]){
            c++;
            si++;
            ans= max(ans,c);
        }
    }
    cout<<ans<<endl;

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