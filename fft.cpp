// use ...\> g++ <name>.cpp -std=c++11 for compiling.
/*
    Fast Fourier Transform (FFT) for polynomial multiplication.
*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i = n;i < m;i++)
#define pb push_back
typedef long long int ll;
typedef pair<ll,ll> Point;
typedef complex<double> cd;
#define max(a,b) a >= b ? a:b
#define min(a,b) a >= b ? b:a
#define X first
#define Y second
#define N 1000000007
ll next_pow_of_two(ll x)
{
    ll i = 0;
    ll n = x;
    while(x > 0)
    {
        x /= 2;
        i++;
    }
    return (1<<(i-1) == n)? n: 1<<i;
}
///////// Recursive FFT //////////
vector<cd>fft(vector<cd>& a)
{
    ll n = a.size();
    if (n == 1) return vector<cd>(1,a[0]);
    vector<cd>w;
    rep(i,0,n)
    {
        double alpha = 2*M_PI*i/n;
        w[i] = cd(cos(alpha),sin(alpha));
    }
    vector<cd>A0(n/2),A1(n/2);
    rep(i,0,n/2)
    {
        A0[i] = a[i*2];
        A1[i] = a[i*2+1];
    }
    vector<cd> y0 = fft(A0);
    vector<cd> y1 = fft(A1);

    vector<cd>y(n);
    rep(i,0,n/2)
    {
        y[i] = y0[i] + w[i]*y1[i];
        y[i + n/2] = y0[i] - w[i]*y1[i];
    }
    return y;
}
///////// Recursive FFT //////////
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll m,n;cin>>m>>n;
    vector<cd>a,b;
    cd x;   
    rep(i,0,n)
    {
        cin>>x;a.pb(x);
    }
    rep(i,0,m)
    {
        cin>>x;b.pb(x);
    }
    //////// Making the degree of the product of polynomials the nearest power of two /////////
    n = next_pow_of_two(m+n);
    rep(i,0,n-a.size()) a.pb(0);
    rep(i,0,n-b.size()) b.pb(0);
    //////// Making the degree of the product of polynomials the nearest power of two /////////
    return 0;
}
