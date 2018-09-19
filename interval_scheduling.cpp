// use ...\> g++ <name>.cpp -std=c++11 for compiling.
/*
    Interval Scheduling (Greedy)
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
    ll n,x,y;cin>>n;
    vector< pair<ll,ll> >v;
    rep(i,0,n)
    {
        cin>>x>>y;
        v.pb(make_pair(y,x));
    }
    sort(v.begin(),v.end());
    cout<<'\n';
    for(auto x:v) cout<<x.S<<' '<<x.F<<'\n';
    vector< pair<ll,ll> >fin;
    fin.pb(v[0]);
    ll i = 0;
    rep(j,i+1,n)
    {
        if (v[j].S >= v[i].F)
        {
            fin.pb(v[j]);
            i = j;
        }
    }
    cout<<'\n';
    for(auto x:fin) cout<<x.S<<' '<<x.F<<'\n';
    return 0;
}
