#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define endl "\n"
#define ll long long int
#define vi vector<int>
#define vll vector<ll>
#define vvi vector < vi >
#define pii pair<int,int>
#define pll pair<long long, long long>
#define mod 1000000007
#define limit 100005
#define inf 1000000000000000001;
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)
#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)
#define gi(x) scanf("%d",&x)
#define gl(x) scanf("%lld",&x)
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)
#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) printf("%lld ",x)
#define pln(x) printf("%lld\n",x)
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")
#define fs first
#define sc second
#define pb push_back
using namespace std;
int n,m,k;
string s[501];
string ans[501];
int dp[501][501];
int mxdepth = -1;
vector<vector<int> > toremove;
void call(int i,int j)
{
    queue<vector<int> > q;
    vector<int> v;
    v.pb(i);
    v.pb(j);
    v.pb(1);
    q.push(v);
    while(q.size())
    {
        vector<int> p = q.front();
        q.pop();
        int x = p[0];
        int y = p[1];
        int dist= p[2];

        if(s[x][y]=='.'&&dp[x][y]==0)
        {
            dp[x][y]=dist;
            mxdepth = max(mxdepth,dist);
            vector<int> temp;
            temp.pb(-dist);
            temp.pb(x);
            temp.pb(y);
            toremove.pb(temp);
            if(x>0)
            {
                vector<int> vv;
                vv.pb(x-1);
                vv.pb(y);
                vv.pb(dist+1);
                q.push(vv);
            }
            if(y>0)
            {
                vector<int> vv;
                vv.pb(x);
                vv.pb(y-1);
                vv.pb(dist+1);
                q.push(vv);

            }
            if(y<m-1)
            {
                vector<int> vv;
                vv.pb(x);
                vv.pb(y+1);
                vv.pb(dist+1);
                q.push(vv);

            }
            if(x<n-1)
            {
                vector<int> vv;
                vv.pb(x+1);
                vv.pb(y);
                vv.pb(dist+1);
                q.push(vv);
            }
        }
    }
}

void solve()
{
    cin>>n>>m>>k;
    rep(i,n)
    {
        cin>>s[i];
        ans[i] =s[i];
    }
    // call bfs
    rep(i,n)
    {
        rep(j,m)
        {
            if(s[i][j]=='.')
            {
                call(i,j);
                goto x;
            }
        }
    }
    x:;

    // rep(i,n)
    // {
    //     rep(j,m)
    //         pis(dp[i][j]);
    //     pnl();
    // }
    sort(toremove.begin(),toremove.end());
    rep(i,k)
    {
        ans[toremove[i][1]][toremove[i][2]]='X';
    }
    rep(i,n)
    {
            cout<<ans[i]<<endl;
    }

}

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
    T=1;
     // cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
        solve();
	}
	return 0;
}
