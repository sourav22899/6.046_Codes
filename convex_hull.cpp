// use ...\> g++ <name>.cpp -std=c++11 for compiling.
/*
    Convex Hull
*/
#include<bits/stdc++.h>
using namespace std;
#define rep(i,n,m) for(int i = n;i < m;i++)
#define pb push_back
typedef long long int ll;
typedef pair<ll,ll> Point;
#define max(a,b) a >= b ? a:b
#define min(a,b) a >= b ? b:a
#define X first
#define Y second
#define N 1000000007

Point p0;

ll orientation(Point p,Point q,Point r)
{
    ll x = ((r.Y - q.Y)*(q.X - p.X))-((q.Y - p.Y)*(r.X - q.X));
    if (x == 0) return 0;
    return (x > 0) ? -1:1; // CCW = -1; CW = 1;
}

ll sq_dist(Point p,Point q)
{
    return (p.X - q.X)*(p.X - q.X) + (p.Y - q.Y)*(p.Y - q.Y); 
}

bool compare(const Point &p,const Point &q)
{
    int l = orientation(p0,p,q);
    if (l == 0) return sq_dist(p0,p) < sq_dist(p0,q);
    return (l == -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    ll n,x,y;cin>>n;
    vector< Point >v;
    rep(i,0,n)
    {
        cin>>x>>y;
        v.pb(make_pair(x,y));
    }
    ll temp = 0;
    ll i = 0;

    /////// Keeping the left corner vertex at v[0] ///////
    for(i = 0;i<v.size();++i)
    {
        Point x = v[i];
        if(x.Y < v[temp].Y || (x.Y == v[temp].Y && x.X <= v[temp].X)) temp = i;
    }
    swap(v[0],v[temp]);
    /////// Keeping the left corner vertex at v[0] ///////

    //for(auto x:v) cout<<x.X<<' '<<x.Y<<'\n';
    p0 = v[0];
    //cout<<p0.X<<' '<<p0.Y<<'\n';
    sort(v.begin()+1,v.end(),compare);
    cout<<'\n';
    //for(auto x:v) cout<<x.X<<' '<<x.Y<<'\n';

    /////// Removing colinear points ////////
    vector < Point > V;
    V.pb(v[0]);
    rep(i,1,v.size()-1)
    {
        if(orientation(p0,v[i],v[i+1]) == 0) continue;
        V.pb(v[i]);
    }
    V.pb(v[v.size()-1]);
    /////// Removing colinear points ////////

    Point top;
    if(V.size() < 3) cout<<"Convex Hull not possible"<<'\n';
    else
    {
        stack< Point >hull;
        hull.push(V[0]);
        hull.push(V[1]);
        hull.push(V[2]);
        rep(i,3,V.size())
        {
            top = hull.top();
            hull.pop();
            while(orientation(hull.top(),top,V[i]) != -1)
            {
                top = hull.top();
                hull.pop();
            }
            hull.push(top);
            hull.push(V[i]);   
        }
        //////// printing the convex hull /////////
        while(hull.empty() == false)
        {
            top = hull.top();
            cout<<top.X<<' '<<top.Y<<'\n';
            hull.pop();
        }
        //////// printing the convex hull /////////
    }
    //for(auto x:V) cout<<x.X<<' '<<x.Y<<'\n';
    return 0;
}
