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
int L[1000005];
int R[1000005];
std::vector<pair<int,int> > v;

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	// cin>>T;
    T =1;
    // cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
    	int n,x,y;
		cin>>n>>x>>y;
		rep(i,n)
		{
			int s,t;
			cin>>s>>t;
			v.pb(make_pair(s,t));
		}
		rep(i,x)
		{
			int v;
			cin>>v;
			L[v]=1;
		}
		rep(i,y)
		{
			int w;
			cin>>w;
			R[w]=1;
		}

		forup(i,1,1000005)
		{
			if(L[i]==1)
				L[i]=i;
			else
				L[i]= L[i-1];
		}
		fordn(i,1000004,-1)
		{
			if(R[i]==1)
				R[i]=i;
			else
				R[i]= R[i+1];
		}
		int ans=mod;
		rep(i,v.size())
		{
			int a = R[v[i].sc];
			int b = L[v[i].fs];
			if(a>0 && b>0)
			ans = min(ans,a-b+1);
		}
		cout<<ans<<endl;
	}
	return 0;
}
