#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <string.h>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include<unordered_map>
#include <string>
#include <cassert>
 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
 
#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)
 
#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)
 
#define slenn(s,n) for(n=0; s[n]!=13 and s[n]!=0; ++n);s[n]=0
 
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
#define ll long long
#define pb push_back
#define MOD 1000000007
#define limit 10000005
#define INF 1000000000
#define ull unsigned long long
using namespace std;
ull mod_pow(ull num, ull pow, ull mod)
{
    ull test,n = num;
    for(test = 1; pow; pow >>= 1)
    {
        if (pow & 1)
            test = ((test % mod) * (n % mod)) % mod;
        n = ((n % mod) * (n % mod)) % mod;
    }
    return test; /* note this is potentially lossy */
}
//while((getchar())!='\n'); //buffer clear
ll gcd(ll a,ll b)
{	ll r;
	while(b)
	{	r= a%b;a = b; b = r;
	}
	return a;
}
int arr[200];
int n; 
ll dp[101][101];
ll ans(int i,int j)
{
	if(dp[i][j]!=-1&&i>=0&&j>=0&&i<=j)
	{
	//	cout<<"dp "<<i<<" "<<j<<" "<<"return "<<dp[i][j]<<endl;
	
		return dp[i][j]%MOD;
	}
	//cout<<"in"<<i<<" "<<j<<endl;
	if(i<0 || j<0 || i>=j)
	{
	//	cout<<"exists1 "<<i<<" "<<j<<" "<<"return "<<0<<endl;
		dp[i][j]=0ll;
		return 0;
	}
	

	ll temp =0;
	//cout<<"----------------------------"<<endl;
	temp+=ans(i,j-1);
	for (int x =i;x<=j;x++)
	{
		if(arr[j]==-arr[x]&& arr[j]>0)
		{	
	///		cout<<"match at "<<x<<" "<<j<<endl;
	
			temp+=(ll)(ans(i,x-1)+1)*(ans(x+1,j-1)+1);
			temp%=MOD;
		}
	}
	//cout<<"----------------------------"<<endl;
	//cout<<"exists3 "<<i<<" "<<j<<" "<<"return "<<temp<<endl;
	dp[i][j]=temp;
	return temp;

} 

int main()
{
	rep(i,101)
	{
		rep(j,101)
			dp[i][j]=-1ll;
	}
	gi(n);
	rep(i,n)
		gi(arr[i]);

	ll out = ans(0,n-1);
	cout<<out+1<<endl;
}