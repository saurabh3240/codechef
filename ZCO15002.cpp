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
int dp[65004];

int main()
{
	std::ios::sync_with_stdio(false);
	int T;
	// cin>>T;
    T =1;
    // cin.ignore(); must be there when using getline(cin, s)
	while(T--)
	{
        int n,k,x;
        cin>>n>>k;
        vector<int> v;
        rep(i,n)
        {
            cin>>x;
            v.pb(x);
        }
        int ans =0;
        std::vector<int>:: iterator it,it2;
        sort(v.begin(),v.end());
        int i=0,j=1;
        for(;i<n;)
        {
            if(abs(v[j]-v[i])>=k)
            {
                ans+=(n-j);
                i++;
            }
            else
                j++;
        }
        // ansmx = max(ansmx,curmx);
         cout<<ans<<endl;
	}
	return 0;
}
