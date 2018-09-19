// use ...\> g++ <name>.cpp -std=c++11 for compiling.
/*
    Weighted Interval Scheduling (DP)
*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i = n;i < m;i++)
#define pb push_back
typedef long long int ll;
#define max(a,b) a >= b ? a:b
#define min(a,b) a >= b ? b:a
#define F first
#define S second
#define N 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,x,y,w;cin>>n;
    vector< pair< pair<ll,ll>,ll> >v;
    rep(i,0,n)
    {
        cin>>x>>y>>w;
        v.pb(make_pair(make_pair(y,x),w));
    }
    sort(v.begin(),v.end());
    cout<<'\n';
    for(auto x:v) cout<<x.F.S<<' '<<x.F.F<<' '<<x.S<<'\n';
    for(ll i = n-1;i > -1;i--)
    {
        ll t = -N;
        rep(j,i+1,n)
        {
            if(v[j].F.S>=v[i].F.F)      
            {
                if(v[j].S > t) t = v[j].S;
            }
        }
        if (t > -N) v[i].S += t;
    }
    cout<<'\n';
    for(auto x:v) cout<<x.F.S<<' '<<x.F.F<<' '<<x.S<<'\n';
    
    return 0;
}
