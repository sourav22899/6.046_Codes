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
vector<cd> fft(vector<cd>& a)
{
    ll n = a.size();
    if (n == 1) return vector<cd>(1,a[0]);
    vector<cd>w(n);
    rep(i,0,n)
    {
        double alpha = 2*M_PI*i/n;
        w[i] = cd(cos(alpha),sin(alpha));
    }
    vector<cd> A0(n/2), A1(n/2);
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

///////// Recursive IFFT //////////
vector<cd> ifft(vector<cd>& a)
{
    ll n = a.size();
    vector<cd>x(n),y(n);
    rep(i,0,n) x[i] = conj(a[i]);
    y = fft(x);
    rep(i,0,n) y[i] = conj(y[i]);
    //y /= y.size();
    rep(i,0,y.size()) y[i] /= n;
    return y;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll m,n;cin>>n>>m;
    vector<cd>a;
    vector<cd>b;
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
    ll k = next_pow_of_two(m+n);
    rep(i,0,k-n) a.pb(0);
    rep(i,0,k-m) b.pb(0);

    vector<cd>A = fft(a);
    vector<cd>B = fft(b);
    ////// Printing fft(a) //////
    for(auto x:A) cout<<x<<'\n';
    cout<<'\n';

    ////// Printing fft(b) //////
    for(auto x:B) cout<<x<<'\n';
    cout<<'\n';

    vector<cd>c(k);
    rep(i,0,k) c[i] = A[i]*B[i];

    ////// If want to print the entire iFFT , then remove ".real()" in Line 105. ////////
    vector<cd>prod = ifft(c);
    rep(i,0,k) cout<<prod[i].real()<<' ';
    cout<<'\n';
    return 0;
}
